import re

INPUT_FILE = "temp_syntax.yy"

tokens_defs = {
    "keywords" : [
        "AUTO",
        "BOOL",
        "BREAK",
        "CASE",
        "CHAR",
        "COMPLEX",
        "CONST",
        "CONTINUE",
        "DEFAULT",
        "DO",
        "DOUBLE",
        "ELSE",
        "ENUM",
        "EXTERN",
        "FLOAT",
        "FOR",
        "GOTO",
        "IF",
        "IMAGINARY",
        "INLINE",
        "INT",
        "LONG",
        "REGISTER",
        "RESTRICT",
        "RETURN",
        "SHORT",
        "SIGNED",
        "SIZEOF",
        "STATIC",
        "STRUCT",
        "SWITCH",
        "TYPEDEF",
        "UNION",
        "UNSIGNED",
        "VOID",
        "VOLATILE",
        "WHILE",
    ],

    "identifier" : [
        "IDENTIFIER",
    ],

    "literal" : [
        "LITERAL"
    ],

    "string_literal" : [
        "STRING_LITERAL"
    ],

    "delimeters" : [
        "SEMICOLON",
        "COMMA",
        "COLON",
        "LEFT_PAR",
        "RIGHT_PAR",
        "DOT",
        "LEFT_CBRACKET",
        "RIGHT_CBRACKET",
        "LEFT_BRACKET",
        "RIGHT_BRACKET",
    ],

    "operators" : [
        "ASSIGN_OP",
        "AMP",
        "LOG_NOT_OP",
        "BIN_NOT_OP",
        "MINUS",
        "PLUS",
        "STAR",
        "SLASH",
        "MOD_OP",
        "G_OP",
        "L_OP",
        "BIN_XOR_OP",
        "BIN_OR_OP",
        "TERNARY_OP",
        "ELLIPSIS",
        "RIGHT_ASSIGN",
        "LEFT_ASSIGN",
        "ADD_ASSIGN",
        "SUB_ASSIGN",
        "MUL_ASSIGN",
        "DIV_ASSIGN",
        "MOD_ASSIGN",
        "AND_ASSIGN",
        "XOR_ASSIGN",
        "OR_ASSIGN",
        "RIGHT_OP",
        "LEFT_OP",
        "INC_OP",
        "DEC_OP",
        "PTR_OP",
        "AND_OP",
        "OR_OP",
        "LE_OP",
        "GE_OP",
        "EQ_OP",
        "NE_OP",
    ],
}


if __name__ == "__main__":
    input_syntax = ""

    with open(INPUT_FILE, "r") as f:
        input_syntax = f.read()
    
    # Removing existing actions
    input_syntax = re.sub(r"({.*?})", "", input_syntax)

    # Find token to type map
    tokens = {}
    for token_type, tokens_list in tokens_defs.items():
        for name in tokens_list:
            tokens[name] = token_type

    # Need to find iteratively grammar and add semantic actions
    # First, separate grammars and its defenitions from each other
    grammars_strs = re.findall(r"\s*?([\w|_]*?):((\s|\S)*?);", input_syntax)

    # Derive specific rules
    grammars = []
    for g_str in grammars_strs:
        name = g_str[0].strip()
        rules = g_str[1]
        grammars.append((name, [s.strip() for s in rules.split("|")]))
    
    # Generate semantic actions
    res = []
    for g_name, g_rules in grammars:
        rules = []
        for rule in g_rules:
            names = rule.strip().split()
            action = ""

            # Generating action for the rule
            # Find if it is recursive one
            rec_idx = -1
            if g_name in names:
                rec_idx = names.index(g_name) + 1
            
            constructor_arg = []
            for idx, ident in enumerate(names):
                if idx == rec_idx:
                    continue
                if ident in tokens.keys():
                    constructor_arg.append("new AstToken(\"{}_{}\", {{}})".format(tokens[ident], ident))
                else:
                    constructor_arg.append("${}".format(idx + 1))
            
            if rec_idx == -1:
                action = "$$ = new AstToken(\"{}\", {{ {} }});".format(g_name, ",".join(constructor_arg))
            else:
                for child in constructor_arg:
                    action = action + "${}->children.push_back({});".format(rec_idx, child)
                action += "$$ = ${}".format(rec_idx)
            
            action = "{" + action + "}"

            rules.append((names, action))
            

        res.append((g_name, rules))

    # Printing the result
    for g_name, g_rules in res:
        print("{}:".format(g_name))
        for rule, action in g_rules[:-1]:
            print("   {} {} |".format(" ".join(rule), action))
        print("   {} {} ;".format(" ".join(g_rules[-1][0]), g_rules[-1][1]))
        print("")

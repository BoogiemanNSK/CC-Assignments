# ifndef DRIVER_HH

# define DRIVER_HH
# include <string>
# include <map>
# include "parser.hh"

# define YY_DECL yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

class driver
{
    public:
        driver ();
        void scan_begin ();
        void scan_end ();
        int parse (const std::string& f);

        std::map<std::string, int> variables;
        std::string file;

        int result;
        bool trace_parsing;
        bool trace_scanning;
};

# endif // ! DRIVER_HH
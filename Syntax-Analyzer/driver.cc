#include "driver.hh"
#include "parser.hh"

driver::driver ()
: trace_parsing (false), trace_scanning (false)
{
    variables["one"] = 1;
    variables["two"] = 2;
}

int driver::parse (const std::string &f)
{
    file = f;

    scan_begin ();
    yy::parser parse (*this);
    int res = parse ();
    scan_end ();
    
    return res;
}
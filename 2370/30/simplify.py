import sys

import boolexpr as b

if __name__ == "__main__":
    expr = b.parse(sys.argv[0])
    print(expr.simplify())

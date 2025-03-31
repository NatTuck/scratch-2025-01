
from numbers import Number
from functools import total_ordering

@total_ordering
class NumErr:
    """Represents a number with uncertainty."""
    def __init__(self, val, err=0):
        if isinstance(val, NumErr):
            self.val = val.val
            self.err = val.err + err
        else:
            self.val = val
            self.err = err
    
    def __add__(self, yy):
        if isinstance(yy, Number):
            yy = NumErr(yy, 0)
        return NumErr(self.val + yy.val, self.err + yy.err)

    def __sub__(self, yy):
        if isinstance(yy, Number):
            yy = NumErr(yy, 0)
        return NumErr(self.val - yy.val, self.err + yy.err)
    
    def frac_err(self):
        return self.err / abs(self.val)
    
    def __mul__(self, yy):
        if isinstance(yy, Number):
            yy = NumErr(yy, 0)
        val = self.val * yy.val
        err = abs(val * (self.frac_err() + yy.frac_err()))
        return NumErr(val, err)

    def __truediv__(self, yy):
        if isinstance(yy, Number):
            yy = NumErr(yy, 0)
        val = self.val / yy.val
        err = abs(val * (self.frac_err() + yy.frac_err()))
        return NumErr(val, err)

    def __floordiv__(self, yy):
        if isinstance(yy, Number):
            yy = NumErr(yy, 0)
        val = self.val // yy.val
        err = abs(val * (self.frac_err() + yy.frac_err()))
        return NumErr(val, err)
    
    def __repr__(self):
        return f"NumErr({self.val}, {self.err})"

    def __str__(self):
        return f"{self.val}±{self.err}"

    def __eq__(self, yy):
        err = self.err + yy.err
        diff = abs(self.val - yy.val)
        return diff <= err

    def __lt__(self, yy):
        return self.val < yy.val
    

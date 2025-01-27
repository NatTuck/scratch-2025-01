
# Design a function that takes
# a string and pads it to 40 charaters
# with spaces added on the left.

def leftpad(text: str) -> str:
    """Left-pad a string to 40 characters."""
    while len(text) < 40:
        text = " " + text
    return text

def test_leftpad():
    assert leftpad("") == " " * 40
    assert leftpad("hello") == " " * 35 + "hello"

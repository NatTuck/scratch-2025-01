
## New Languge: Python

- Syntax: Correct indentation, keywords like "def", etc.
- Semantics

Python program execution:

- Start at a main source file.
- Execute one statement (typically a line) at a time, top to bottom.


### Design Recipe

- Names: Function name and parameter names
  - We put in a purpose statement now too.
- Write down types.
- Write a test function
- Start with the standard pattern
- Write the code for the function body


```python
def double(x: int) -> int:
  """Double an integer"""
  return x + x

def test_double():
  assert double(7) == 14
```


### Complex example

```python
def sum(xs: list[int]) -> int:
  """Sum up a list of integers."""
  y = 0
  for x in xs:
    y += x
  return y

def test_sum():
  assert sum([1,2,3]) == 6

def sum_lists(xss: list[list[int]]) -> list[int]):
  """Given a list of lists, sum each list."""
  ys = []
  for xs in xss:
    ys.append(sum(xs))
  return ys

def test_sum_lists():
  assert sum_([[1,2,3], [2,4,6,8]]) == [6, 20]
```


## Data Types in Python

Built in:

- Lists - An ordered sequence
- Sets - Unordered collection, no duplicates
  - Very efficient "in" operation. 
- Dictionary - A colleciton of key => value pairs that
  allows fast lookup by key.
- Tuple - An immutable, fixed length sequence.

Custom:

- namedtuple: Lets us create "struct" or "record" types.
- classes: Lets us create custom object types.


```python
namedtuple("Student", ['name', 'student_id', 'credits_earned'])
```


## Object Oriented Programming

- Classes have methods.
- Classes can inherit from other classes to allow us to
  share code between different types of object.


## Practical Applications

- Graphical applications / games
- Text processing with regular expressions
- Data processing
- Automatically genenerating really bad kids storybooks
- Web Development

## Conceptual Assignments

- Sorting
- Computational Complexity






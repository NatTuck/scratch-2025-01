
item_count = 0


class LibraryItem:
    def __init__(self, title):
        print("init LibraryItem")

        global item_count
        if not hasattr(self, 'title'):
            item_count = item_count + 1

        self.title = title
        self.checked_out = False

    def check_out(self):
        if not self.checked_out:
            self.checked_out = True
            print(f"Check out {self}")
            return True
        else:
            print(f"Error: already checked out {self}")
            return False

    def return_item(self):
        self.checked_out = False

        
class Book(LibraryItem):
    def __init__(self, title, author):
        print("init Book")
        LibraryItem.__init__(self, title)
        self.author = author

    def __repr__(self):
        return f"Book({self.title}, {self.author})"

    
class DVD(LibraryItem):
    def __init__(self, title, director):
        print("init DVD")
        LibraryItem.__init__(self, title)
        self.director = director

    def __repr__(self):
        return f"DVD({self.title}, {self.director})"

class HybridItem(Book, DVD):
    def __init__(self, title, author, director):
        print("init Hybrid")
        Book.__init__(self, title, author)
        DVD.__init__(self, title, director)

    def __repr__(self):
        return f"Hybrid({self.title}, {self.author}, {self.director})"


class Library:
    def __init__(self):
        self.items = []

    def add_item(self, item):
        self.items.append(item)

    def check_out(self, title):
        for item in self.items:
            if item.title == title:
                if item.check_out():
                    return item
        raise Exception("No item available");
        


def make_lib():
    d = DVD("Jurrassic Park", "Speilberg")
    b = Book("Jurrassic Park", "Crighton")
    h = HybridItem("Intro to Film", "Author", "Spielberg")

    lib = Library()
    lib.add_item(d)
    lib.add_item(b)
    lib.add_item(h)
    return lib

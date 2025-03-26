import bz2

def read_index():
    file = "simplewiki-20250301-pages-articles-multistream-index.txt"
    offsets = {}
    with open(file) as fh:
        for line in fh:
            (title, offset) = get_fields(line)
            offsets[title] = offset
    return offsets
        
def get_fields(line: str) -> tuple[str, int]:
    """Get the article title and offset from a line in the index"""
    fields = line.strip().split(':', 2)
    
    return (fields[2], int(fields[0]))

def test_get_fields():
    assert get_fields("536:21:Arithmetic") == ("Arithmetic", 536)
    assert (get_fields("1000:58:Terminator: Salvation") == 
        ("Terminator: Salvation", 1000))

def read_data(name):
    idx = read_index()
    file = "/home/nat/Downloads/simplewiki-20250301-pages-articles-multistream.xml.bz2"
    with open(file, "rb") as fh:
        offset = idx[name]
        fh.seek(offset)
        bs = fh.read(1024 * 1024)
        
        de = bz2.BZ2Decompressor()
        text = de.decompress(bs)
        print(text)
        
read_data("Spider")        
        
    
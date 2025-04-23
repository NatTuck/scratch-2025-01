
from http.server import HTTPServer, BaseHTTPRequestHandler
from pathlib import Path

class Page:
    def html(self):
        return f'''
        <!doctype html>
        <html>
            <head>
                <title>{self.title}</title>
            </head>
            <body>
                <h1>{self.title}</h1>
                {self.body}
            </body>
        </html>
        '''

    def bytes(self):
        return self.html().encode('utf-8')


class Welcome(Page):
    title = 'Welcome!'
    body = '''
    <p>Welcome to our website</p>
    <p>We have <a href="/page2">another page.</p>
    '''

class Page2(Page):
    title = "Page 2"
    body = '''
    <p><strong>This is the second page.</strong></p>
    <p>Back to the <a href="/">welcome page</a>.</p>
    <div>
        <h2>Get Form</h2>
        <form action="/page3">
            <p>Search query:<br>
            <input type="text" name="q">
            </p>
            <p><input type="submit"></p>
        </form>
    </div>
    <div>
        <h2>Post Form</h2>
        <form action="/page3" method="post">
            <p>Search query:<br>
            <input type="text" name="q">
            </p>
            <p><input type="submit"></p>
        </form>
    </div>
   
    '''

class Page3(Page):
    title = "Page 2"
    
    def set_body(self, query): 
        self.body = f'''
        <p><i>This is the third page.</i></p>
        <p>Your query was "#{query}".</p>
        '''

class Handler(BaseHTTPRequestHandler):
    routes = {
        "/": Welcome,
        "/page2": Page2,
        "/page3": Page3
    }

    def do_GET(self):
        query = False
        path = self.path

        if "?" in path:
            [path, query] = self.path.split('?', 2)

        print("path=", path)
        print("query=", query)

        if not path in self.routes:
            self.send_response(404)
            return

        self.close_connection = True

        self.send_response(200)
        self.send_header("content-type", "text/html; charset=UTF-8")
        self.end_headers()
    
        page = self.routes[path]()

        if query:
            page.set_body(query)

        self.wfile.write(page.bytes())

    def do_POST(self):
        self.send_response(200)
        self.send_header("content-type", "text/html; charset=UTF-8")
        self.end_headers()
       
        print("Request body:")
        print(self.rfile.read(-1))
        print("Body done.")

        self.wfile.write(b"You submitted a post request.")


if __name__ == '__main__':
    server = HTTPServer(('', 8081), Handler)
    server.serve_forever()

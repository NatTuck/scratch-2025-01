## HTTP Request types

### GET /foo/bar HTTP/1.1

Simple get request: Send me back a resource (file).

This style of request is typically cacheable - if I request the
same path twice I'll get the same file.


### GET /foo/bar?q=some query HTTP/1.1

Makes a (search-like) query of the web site.

Not typically cachable - results will be different, potentially
even for the same query.


### POST /auth/login HTTP/1.1

Headers:
Content-type: application/multipart-form-data

Body:
email=nt1171@usnh.edu&password=secret1234




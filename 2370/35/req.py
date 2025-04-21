#!/usr/bin/env python

import requests
import bs4

resp = requests.get("https://homework.quest")
# print(resp.status_code)
resp.raise_for_status()

tree = bs4.BeautifulSoup(resp.text, 'html.parser')

print(tree)





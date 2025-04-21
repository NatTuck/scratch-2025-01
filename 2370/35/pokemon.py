#!/usr/bin/env python

import requests
import bs4

def main():
    resp = requests.get("https://en.wikipedia.org/wiki/List_of_Pok%C3%A9mon")
    resp.raise_for_status()

    tree = bs4.BeautifulSoup(resp.text, 'html.parser')

    tabs = tree.select('table')

    for tab in tabs:
        cap = tab.select('caption')
        if len(cap) < 1:
            continue

        targetCap = "List of Pokémon species names by generation"
        if cap[0].text.startswith(targetCap):
            extract_pokemon(tab)


def extract_pokemon(tab):
    rows = tab.select('tr')
    head = rows[0]

    gens = []
    for gen in head.select('th'):
        gens.append(gen.text.strip())

    result = {}
        
    body = rows[2:]
    col = 0
    for row in body:
        cells = row.select('td')
        while len(cells) >= 2:
            try:
                numb = int(cells[0].text)
                name = cells[1].select('a')[0].text
                cells = cells[2:]
                ys = result.get(gens[col], [])
                ys.append((numb, name))
                result[gens[col]] = ys
            except ValueError:
                cells = cells[1:]
            col += 1
        col = 0

    print(result)
                
          
if __name__ == '__main__':
    main()


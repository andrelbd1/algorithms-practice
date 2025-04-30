import requests
import requests_cache
from dataclasses import dataclass
from requests import Response
from typing import Final


URL: Final = 'https://poetrydb.org'  # https://github.com/thundercomb/poetrydb#readme

requests_cache.install_cache('cache/poetry_cache/example_2', 
                             expire_after=3600,
                             backend='sqlite',
                             allowable_methods=['GET'],
                             allowable_codes=(200, 404),
                             old_cache=True)


@dataclass
class Poem:
    title: str
    author: str
    linecount: str


def get_poem(title: str) -> Poem:
    try:
        response: Response = requests.get(f'{URL}/title/{title}/author,title,linecount.json')
        response.raise_for_status()  # Raise an error for bad responses
        result: list = response.json()
        if not result:
            raise ValueError('No results found')
        json: dict = result[0]
        source: str = 'CACHE' if getattr(response, 'from_cache', False) else 'API'
        print(f'Source: {source}')
        poem = Poem(**json)
        print(f'Poem {poem.title} by {poem.author} with {poem.linecount} lines')
    except Exception as e:
        print(f'{response.status_code} - {e}')


if __name__ == '__main__':
    get_poem('Ozymandias')
    get_poem('Easter Week')
    print('------------------')
    get_poem('Ozymandias')
    get_poem('Easter Week')

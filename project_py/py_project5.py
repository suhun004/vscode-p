import requests
from bs4 import BeautifulSoup

res = requests.get('https://www.konkuk.ac.kr')
soup = BeautifulSoup(res.text, 'html.parser')

print(soup.select('h1').text)
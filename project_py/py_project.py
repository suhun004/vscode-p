menu = {
  '아메리카노' : 3500,
  '라떼' : 4000,
  '아이스티' : 3200
}
i = 4
p = 0
while i != 0:
  i = int(input('아메리카노는 1, 라뗴는 2, 아이스티는 3, 종료하려면 0을 눌러주세요 : '))
  if i == 1:
    print('아메리카노')
    p += menu['아메리카노']
  elif i == 2:
    print('라떼')
    p += menu['라떼']
  elif i == 3:
    print('아이스티')
    p += menu['아이스티']
  elif i != 0:
    print('다시 입력하세요')
print(p, '원 입니다')
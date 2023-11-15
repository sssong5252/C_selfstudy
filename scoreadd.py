b = 0
while True:
    a = input('학번, 이름, 성적을 입력하시오(음수이면 종료): ')
    a.split(',')
    a[2] = b
    if a < 0:
        print("종료합니다.")
        break
    elif a[2] > 0:
        b += b
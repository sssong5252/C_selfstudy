while True:
    num =int(input('학번을 입력하세요: '))
    name = input('이름을 입력하세요: ')
    score = input('학점을 입력하세요')

    if name == '송준용':
        print('송준용: %d, 학점: %s' %num %score)
    if name == '0':
        print('종료')
        break
    

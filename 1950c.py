for i in range(int(input())):
    hour, minute = input().split(':')
    hour_ = int(hour)%12
    hour_ = 12 if hour_==0 else hour_
    temp = 'AM' if int(hour)<12 else 'PM'
    print(f'{hour_:02d}:{minute} {temp}')

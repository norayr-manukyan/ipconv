import argparse

# #String to Int
def arr_to_int(ip_arr):
    for i in range(0, len(ip_arr)):
        ip_arr[i] = int(ip_arr[i])
    return ip_arr

#Numeral
def numeral(ip):
    ip_arr = arr_to_int(ip)
    numeral_system = ip_arr[3] + ip_arr[2] * 256**1 + ip_arr[1] * 256**2 + ip_arr[0] * 256**3
    return numeral_system

#Hexadecimal
def hex(num):
    x = num // 16
    y = num - x * 16
    if y == 10:
        y = 'A'
    elif y == 11:
        y = 'B'
    elif y == 12:
        y = 'C'
    elif y == 13:
        y = 'D'
    elif y == 14:
        y = 'E'
    elif y == 15:
        y = 'F'

    if x == 10:
        x = 'A'
    elif x == 11:
        x = 'B'
    elif x == 12:
        x = 'C'
    elif x == 13:
        x = 'D'
    elif x == 14:
        x = 'E'
    elif x == 15:
        x = 'F'

    return  (str(x) + str(y))

def ip_arr_to_hex(ip):
    ip_arr = arr_to_int(ip)
    ans='0X'
    for i in range(0,len(ip_arr)):
        ans+=hex(ip_arr[i])
    return ans

#Binary Numeral System
def binary(num):
    ans=''
    binary_arr=[]
    delta = num
    i = 7
    while i >= 0:
        n = delta // 2**i
        if n == 1:
            delta -= 2 ** i
            binary_arr.append('1')
        else:
            binary_arr.append('0')
        i-=1
    ans=('').join(binary_arr)
    return ans

def ip_arr_to_binary(ip):
    ip_arr = arr_to_int(ip)
    ans = ''
    for i in range(0, len(ip_arr)):
        ans += binary(ip_arr[i])
        if i != 3:
            ans += ' '
    return ans

parser = argparse.ArgumentParser()
parser.add_argument('ip')
parser.add_argument('--todec', action='store_true')
parser.add_argument('--tobin', action='store_true')
parser.add_argument('--tohex', action='store_true')
args = parser.parse_args()
ip_arr = args.ip.split('.')

if args.tobin:
    print(ip_arr_to_binary(ip_arr))
elif args.tohex:
    print(ip_arr_to_hex(ip_arr))
else:
    print(numeral(ip_arr))
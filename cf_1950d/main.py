res_set = {1, 10, 11, 100, 101, 110, 111, 121, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 1210, 1221, 1331, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 10201, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 11121, 11211, 12100, 12111, 12210, 12221, 12321, 13310, 13431, 14641, 100000, 100001, 100010, 100011, 100100, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 102010, 102111, 110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 110121, 111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111, 111201, 111210, 111221, 112110, 112211, 112221, 121000, 121011, 121110, 121121, 122100, 122111, 122210, 122211, 122221, 122331, 123210, 123321, 133100, 133221, 134310, 134431, 135531, 146410, 147741, 161051}
for _ in range(int(input())):
    n = int(input())
    print('Yes' if (n in res_set) else 'No')

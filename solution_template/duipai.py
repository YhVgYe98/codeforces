import os
import filecmp
i = 0
while True:
        os.system("python .\\src\\bin\\data_gen.py > std_in")
        os.system(".\\src\\bin\\std.exe < std_in > std_out")
        os.system(".\\target\\release\\myout.exe < std_in > my_out")
        if not filecmp.cmp("my_out", "std_out"):
            print("RA!")
            break
        i += 1
        print("{}\n".format(i))
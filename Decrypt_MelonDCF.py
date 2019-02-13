import os
import hashlib
import traceback

filename="C:\\Users\\NHNEnt\\Desktop\\aa.dcf"

enc_file=open(filename,"rb")
dec_file=open(filename+".mp3","wb")

filesize = os.path.getsize(filename)

data=enc_file.read(filesize)
enc_file.close()

#9125817603
st="9125817603"
data_hash=data[0x0e:0x53]
data_hash+="min"
data_hash+=st
data_hash+=( chr(ord(st[0])^0xFF) + chr(ord(st[1])^0xFF) + chr(ord(st[2])^0xFF) + chr(ord(st[3])^0xFF) +chr(ord(st[4])^0xFF) + chr(ord(st[5])^0xFF) + chr(ord(st[6])^0xFF) + chr(ord(st[7])^0xFF) +chr(ord(st[8])^0xFF) + chr(ord(st[9])^0xFF))
data_hash+="SSE Primary-Level Base Key Generation"

m = hashlib.sha1()
m.update(data_hash)
data_hash=m.digest().encode('hex')

result_hash=""
result_hash+=data_hash

for i in range(2,101):
    data_hash=data_hash.decode('hex')
    data_hash+="min"
    data_hash+=st
    data_hash+=( chr(ord(st[0])^0xFF) + chr(ord(st[1])^0xFF) + chr(ord(st[2])^0xFF) + chr(ord(st[3])^0xFF) +chr(ord(st[4])^0xFF) + chr(ord(st[5])^0xFF) + chr(ord(st[6])^0xFF) + chr(ord(st[7])^0xFF) +chr(ord(st[8])^0xFF) + chr(ord(st[9])^0xFF))
    data_hash+="SSE {0}-Level Base Key Generation".format(i)

    m = hashlib.sha1()
    m.update(data_hash)
    data_hash=m.digest().encode('hex')

    result_hash+=data_hash

result_hash=result_hash.decode('hex')
encrypt_data=data.split(";Size=\"")[1].split("\"\x0d\x0a")[1]

p_data=""
for i in range(0,128):
    p_data+=chr(ord(encrypt_data[i])^ord(result_hash[i]))

try:

    for i in range(128,len(encrypt_data),0x8000):
        b_data=encrypt_data[i:i+0x8000]

        for j in range(0,0x8000):
            if j==len(b_data):
                break

            add_key=j/128

            dv=j%4
            if dv==3:
                xor_key=add_key
            elif dv==2:
                xor_key=i/0x8000%256
            elif dv==1:
                xor_key=i/0x800000%256
            elif dv==0:
                xor_key=0

            p_data+=chr(ord(b_data[j])^ord(result_hash[(j%128)+add_key]) ^ xor_key)

except:
    print traceback.format_exc()

dec_file.write(p_data)
dec_file.close()

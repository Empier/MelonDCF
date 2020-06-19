#include <jni.h>
#include <android/log.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "sha1.h"


int __cdecl HEX(unsigned char *a1)
{
	int result;

	result = 0;
	if ( (signed int)*(unsigned char *)(a1 + 1) >= 97 && (signed int)*(unsigned char *)(a1 + 1) <= 122 )
		result = *(unsigned char *)(a1 + 1) - 87;
	if ( (signed int)*(unsigned char *)(a1 + 1) >= 65 && (signed int)*(unsigned char *)(a1 + 1) <= 'Z' )
		result = result + *(unsigned char *)(a1 + 1) - 55;
	if ( (signed int)*(unsigned char *)(a1 + 1) >= 48 && (signed int)*(unsigned char *)(a1 + 1) <= '9' )
		result = result + *(unsigned char *)(a1 + 1) - 48;
	if ( (signed int)*(unsigned char *)a1 >= 97 && (signed int)*(unsigned char *)a1 <= 'z' )
		result += 16 * (*(unsigned char *)a1 - 87);
	if ( (signed int)*(unsigned char *)a1 >= 65 && (signed int)*(unsigned char *)a1 <= 90 )
		result += 16 * (*(unsigned char *)a1 - 55);
	if ( (signed int)*(unsigned char *)a1 >= 48 && (signed int)*(unsigned char *)a1 <= 57 )
		result += 16 * (*(unsigned char *)a1 - 48);
	return result;
}



extern "C"
void Java_com_naman14_timber_filepicker_model_MarkedItemList_SHA1(JNIEnv *env, jobject callingObj, jstring dir){
//jint Java_com_naman14_timber_activities_MainActivity_SHA1(JNIEnv *env, jobject callingObj, jstring dir){

//jint Java_com_naman14_timber_filepicker_model_MarkedItemList_SHA1(JNIEnv *env, jobject callingObj, jstring dir){



    unsigned char temp[200]={0x00,};
    unsigned char temp2[200]={0x00,};
    unsigned char hash_result[2001]={0x00,};

    char hexresult[41];
    char result[21];
    int len2=0;
    int offset=0;
    int j=0;

    char *path=(char *)env->GetStringUTFChars(dir,NULL);
    char path2[256]="";


    strcpy(path2,path);
    strcat(path2,".mp3");

    FILE *fp=fopen(path,"rb");
    FILE *fp2=fopen(path2,"wb");
    //__android_log_print(ANDROID_LOG_INFO,"KOREAMP","FD: %d",fp);
    env->ReleaseStringUTFChars(dir, path);

   // fclose(fp);
    //fclose(fp2);
    //return 0;
//e4fcb716524e182093b5840141c631b463d284cb
 //   4ed402890c5589e44b44c56696447e1cf6e3a4dc
 //   848497208ee770158eb6b6e829f8f1508e1263f2
 //   581b12c6ccd47c28647161d2d02f4cba7a6ec60e
    fseek(fp, 0, SEEK_END);

    int fileLength = ftell(fp);

    fseek(fp, 0, SEEK_SET);

    unsigned char * data=(unsigned char *)malloc(fileLength);

    fread(data,fileLength,1,fp);

    strncpy((char *)temp,(char *)data+0x0e,69);
    strcat((char *)temp,"\x6d\x69\x6e\x31\x30\x34\x39\x34\x39\x37\x36\x35\x31\xce\xcf\xcb\xc6\xcb\xc6\xc8\xc9\xca\xce");
    strcat((char *)temp,"SSE Primary-Level Base Key Generation");


    SHA1( result, (char *)temp, 129 );

    for(j=0;j<20;j++) {
        hash_result[j]=result[j];
    }

   for(int i=2;i<101;i++)
   {
       memset(temp,0,200);
       memcpy(temp,result,20);
       memcpy(temp+20,"\x6d\x69\x6e\x31\x30\x34\x39\x34\x39\x37\x36\x35\x31\xce\xcf\xcb\xc6\xcb\xc6\xc8\xc9\xca\xce",23);

       sprintf((char *)temp2,"SSE %d-Level Base Key Generation\x00",i);

       len2=strlen((char *)temp2);
       memcpy(temp+43,temp2,len2+1);
       //__android_log_print(ANDROID_LOG_INFO,"KOREAMP","len %d",len2);
       //__android_log_print(ANDROID_LOG_INFO,"KOREAMP","> %s",temp);



       //__android_log_print(ANDROID_LOG_INFO,"KOREAMP","%s",result);

       SHA1( result, (char *)temp, 43+len2 );

       for(j=0;j<20;j++) {
           hash_result[((i-1)*20)+j]=result[j];
       }


       /*
       for( offset = 0; offset < 20; offset++) {
                 sprintf( ( hexresult + (2*offset)), "%02x", result[offset]&0xff);
             }
           __android_log_print(ANDROID_LOG_INFO,"KOREAMP","%s",hexresult);
           */
   }




    unsigned char *tempasdf=0;
    tempasdf=data;

    for(int a=0;a<0x700;a++)
    {
        if(data[a]==';' && data[a+1]=='S' && data[a+2]=='i' && data[a+3]=='z' && data[a+4]=='e' && data[a+5]=='=' && data[a+6]=='\"')
        {

            for(int b=8;b<0x20;b++)
            {

                if(data[a+b]==0x0a)
                {
                    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","OK");
                    data=data+a+b+1;
                    fileLength-=data-tempasdf;
                    break;
                }
            }

            break;

        } else{

            if(a==0x6FF)
            {
                __android_log_print(ANDROID_LOG_INFO,"KOREAMP","FAIL");
                return;
            }
        }
    }

    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","finish");




    /*
    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","1 %x",data);
    data=(unsigned char *)strstr((char *)data,";Size=\"");
    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","2 %x",data);
    data=(unsigned char *)strstr((char *)data,"\"\x0d\x0a")+2;
    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","3 %x",data);

    */
    for(int i=0;i<128;i++)
    {
        data[i]=data[i]^hash_result[i];
    }

    unsigned char pdata[0x8000];
    int over_num=0;
    int add_key=0;
    int xor_key=0;
    int dv=0;

    for(int i=128;i<fileLength;)
    {
        if((i+0x8000)>fileLength)
        {
            over_num=fileLength-i;
            memcpy(pdata, data + i, over_num);

        } else {
            over_num=0x8000;
            memcpy(pdata, data + i, 0x8000);
        }



        for(int j=0;j<over_num;j++)
        {
            add_key=j/128;
            dv=j%4;
            if(dv==3)
                xor_key=add_key;
            else if(dv==2)
                xor_key=i/0x8000%256;
            else if(dv==1)
                xor_key=i/0x800000%256;
            else if(dv==0)
                xor_key=0;

            data[i+j]=pdata[j]^hash_result[(j%128)+add_key]^xor_key;
            //if(i+j==128)
            //{
            //    __android_log_print(ANDROID_LOG_INFO,"KOREAMP","128: %x %d %d",data[i+j],i,j);
           // }
        }

        i=i+over_num;

    }
    //__android_log_print(ANDROID_LOG_INFO,"KOREAMP","128: %x",data[128]);
    fwrite(data,fileLength,1,fp2);


    free(tempasdf);

    fclose(fp);
    fclose(fp2);
}





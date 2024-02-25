/* Assume there is a file
called 'file.c' in c:\tc
directory. */
int main()
{
 FILE *fp;
 fp=fopen("c:\tc\file.c","r");
 /*\t akan dianggap sebagai 'tab', 
 bukan sebagai direktori, sehingga
 program akan menampilkan 'unable to open file*/
 if(!fp)
 printf("Unable to open file.");

 fclose(fp);
 return 0;
}

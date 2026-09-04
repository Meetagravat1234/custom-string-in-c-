#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class STRING
{
        char *s;
        public:
        STRING()
        {
                s=new char[20];
                s[0]='\0';
        }
        STRING(const char *p)
        {
                s=new char[strlen(p)+1];
                strcpy(s,p);
        }
        STRING(const STRING& t)
        {
                s=new char[strlen(t.s)+1];
                strcpy(s,t.s);
        }
        ~STRING()
        {
                if(s!=0)
                        delete []s;
        }
        STRING& operator = (const STRING& t)
        {
                if(this!=&t)
                {
                        delete []s;
                        s=new char[strlen(t.s)+1];
                        strcpy(s,t.s);
                }
                return *this;
        }
        STRING operator + (const STRING& t)
        {
                STRING temp;
                delete []temp.s;

                temp.s=new char[strlen(s)+strlen(t.s)+1];
                strcpy(temp.s,s);
                strcat(temp.s,t.s);

                return temp;
        }
        char operator [] (int index)
        {
                return s[index];
        }
        int operator > (STRING& t)
        {
                char *p=s,*q=t.s;
                while(*p&&*q)
                {
                        if(*p!=*q)
                                return *p>*q;
                        p++;
                        q++;
                }
                return *p>*q;
        }
        int operator < (STRING& t)
        {
                char *p=s,*q=t.s;
                while(*p&&*q)
                {
                        if(*p!=*q)
                                return *p<*q;
                        p++;
                        q++;
                }
                return *p<*q;
        }
        int operator == (STRING& t)
        {
                char *p=s,*q=t.s;
                while(*p&&*q)
                {
                        if(*p!=*q)
                                return 0;
                        p++;
                        q++;
                }
                return (*p==*q);
        }
        int operator != (STRING& t)
        {
                return !(*this==t);
        }
        int operator >= (STRING& t)
        {
                if(*this>t || *this==t)
                        return 1;
                else
                        return 0;
        }
        int operator <= (STRING& t)
        {
                if(*this<t || *this==t)
                        return 1;
                else
                        return 0;
        }
        friend istream& operator >> (istream&,STRING&);
        friend ostream& operator << (ostream&,STRING&);

        friend int strlen(STRING&);
        friend void strcpy(STRING&,STRING&);
        friend void strncpy(STRING&,STRING&,int);
        friend int strcmp(STRING&,STRING&);
        friend int strncmp(STRING&,STRING&,int n);
        friend void strcat(STRING&,STRING&);
        friend void strncat(STRING&,STRING&,int);
        friend void strrev(STRING&);
        friend char* strchr(STRING&,char);
        friend char* strrchr(STRING&,char);
        friend char* strstr(STRING&,char*);
        friend void strupr(STRING&);
        friend void strlwr(STRING&);
};

int strlen(STRING& t)
{
        int len=0;
        char *p=t.s;
        while(*p++)
                len++;
        return len;
}
void strcpy (STRING& t1,STRING& t2)
{
        t1=t2;
}
void strncpy(STRING& t1,STRING& t2,int n)
{
        char *p=t1.s,*q=t2.s;
        while(n && *q)
        {
                *p=*q;
                p++;
                q++;
                n--;
        }
        *p='\0';
}
int strcmp(STRING& t1,STRING& t2)
{
        if(t1==t2)
                return 0;
        else if(t1>t2)
                return 1;
        else
                return -1;
}
int strncmp(STRING& t1,STRING& t2,int n)
{
        char *p=t1.s,*q=t2.s;
        while(n && *p && *q)
        {
                if(*p!=*q)
                        return *p - *q;
                p++;
                q++;
                n--;
        }
        if(n==0)
                return 0;
        return *p - *q;
}
void strcat(STRING& t1,STRING& t2)
{
        t1 = t1+t2;
}
void strncat(STRING& t1,STRING& t2,int n)
{
        int l1=strlen(t1);
        int l2=strlen(t2);
        char *temp=new char[l1+n+1];
        int i=0;
        for(i=0;i<l1;i++)
                temp[i]=t1.s[i];
        for(int j=0;j<n && t2.s[j];j++,i++)
                temp[i]=t2.s[j];
        temp[i]='\0';

        delete []t1.s;
        t1.s=temp;
}
void strrev(STRING& t)
{
        char *p=t.s,*q=t.s+strlen(t)-1;
        char ch;
        while(p<q)
        {
                ch=*p;
                *p=*q;
                *q=ch;
                p++;
                q--;
        }
}
char * strchr(STRING& t,char ch)
{
        char *p=t.s;
        while(*p)
        {
                if(*p==ch)
                        return p;
                p++;
        }
        if(ch=='\0')
                return p;
        return 0;
}
char * strrchr(STRING& t1,char ch)
{
        char *p=t1.s+strlen(t1);
        while(p>=t1.s)
        {
                if(*p==ch)
                        return p;
                p--;
        }
        return 0;
}
char * strstr(STRING& t,char *sub)
{
        char *m=t.s;
        char *a,*b;
        if(*sub=='\0')
                return m;
        while(*m)
        {
                if(*m==*sub)
                {
                        a=m;
                        b=sub;
                        while(*a && *b && *a==*b)
                        {
                                a++;
                                b++;
                        }
                        if(*b=='\0')
                                return m;
                }
                m++;
        }
        return 0;
}
void strupr(STRING& t)
{
        char*p=t.s;
        while(*p)
        {
                if(*p>='a' && *p<='z')
                        *p^=32;
                p++;
        }
}
void strlwr(STRING& t)
{
        char*p=t.s;
        while(*p)
        {
                if(*p>='A' && *p<='Z')
                        *p^=32;
                p++;
        }
}
istream& operator >> (istream& in,STRING& t)
{
        char buffer[100];
        in>>buffer;

        delete []t.s;
        t.s=new char[strlen(buffer)+1];
        strcpy(t.s,buffer);

        return in;
}
ostream& operator << (ostream& out, STRING& t)
{
        out<<t.s;
        return out;
}

int main()
{
        int op;
        while(1)
        {
                cout<<"\nEnter a choice"<<endl;
                cout<<"1)strlen 2)strcpy 3)strncpy 4)strcat 5)strncat 6)strrev 7)strchr 8)strrchr 9)strstr 10)strupr 11)strlwr 12)strcmp 13)strncmp 14)exit"<<endl;
                cin>>op;

                switch(op)
                {
                        case 1:
                        {
                                STRING s1;
                                cout<<"enter string"<<endl;
                                cin>>s1;

                                cout<<"string length: "<<strlen(s1)<<endl;
                                break;
                        }
                        case 2:
                        {
                                STRING s1,s2;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s1>>s2;
                                strcpy(s1,s2);
                                cout<<"copied into 1st string: "<<s1<<endl;
                                break;
                        }
                        case 3:
                        {
                                STRING s4,s5;
                                int n;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s4>>s5;
                                cout<<"enter 'n' to copy 'n' chars"<<endl;
                                cin>>n;
                                strncpy(s4,s5,n);
                                cout<<"copied into 1st string: "<<s4<<endl;
                                break;
                        }
                        case 4:
                        {
                                STRING s1,s2;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s1>>s2;
                                strcat(s1,s2);
                                cout<<"concatenated string: "<<s1<<endl;
                                break;
                        }
                        case 5:
                        {
                                STRING s1,s2;
                                int n;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s1>>s2;
                                cout<<"enter 'n' to concatenate 'n' chars"<<endl;
                                cin>>n;
                                strncat(s1,s2,n);
                                cout<<"concatenated string: "<<s1<<endl;
                                break;
                        }
                        case 6:
                        {
                                STRING s1;
                                cout<<"enter string"<<endl;
                                cin>>s1;
                                strrev(s1);
                                cout<<"reversed string: "<<s1<<endl;
                                break;
                        }
                        case 7:
                        {
                                STRING s1;
                                char ch;
                                cout<<"enter string"<<endl;
                                cin>>s1;
                                cout<<"enter character to find"<<endl;
                                cin>>ch;
                                char *res=strchr(s1,ch);
                                if(res)
                                        cout<<"character found: "<<res<<endl;
                                else
                                        cout<<"character not found"<<endl;
                                break;
                        }
                        case 8:
                        {
                                STRING s1;
                                char ch;
                                cout<<"enter string"<<endl;
                                cin>>s1;
                                cout<<"enter character to find from last"<<endl;
                                cin>>ch;
                                char *res=strrchr(s1,ch);
                                if(res)
                                        cout<<"character found: "<<res<<endl;
                                else
                                        cout<<"character not found"<<endl;
                                break;
                        }
                        case 9:
                        {
                                STRING s1;
                                char sub[100];
                                cout<<"enter main string"<<endl;
                                cin>>s1;
                                cout<<"enter substring to search"<<endl;
                                cin>>sub;
                                char *res=strstr(s1,sub);
                                if(res)
                                        cout<<"substring found: "<<res<<endl;
                                else
                                        cout<<"substring not found"<<endl;
                                break;
                        }
                        case 10:
                        {
                                STRING s1;
                                cout<<"enter string"<<endl;
                                cin>>s1;
                                strupr(s1);
                                cout<<"uppercase string: "<<s1<<endl;
                                break;
                        }
                        case 11:
                        {
                                STRING s1;
                                cout<<"enter string"<<endl;
                                cin>>s1;
                                strlwr(s1);
                                cout<<"lowercase string: "<<s1<<endl;
                                break;
                        }
                        case 12:
                        {
                                STRING s1,s2;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s1>>s2;
                                int res=strcmp(s1,s2);
                                if(res==0)
                                        cout<<"strings are equal"<<endl;
                                else if(res>0)
                                        cout<<"1st string is greater"<<endl;
                                else
                                        cout<<"2nd string is greater"<<endl;
                                break;
                        }
                        case 13:
                        {
                                STRING s1,s2;
                                int n;
                                cout<<"enter 2 strings"<<endl;
                                cin>>s1>>s2;
                                cout<<"enter 'n' to compare 'n' chars"<<endl;
                                cin>>n;
                                int res=strncmp(s1,s2,n);
                                if(res==0)
                                        cout<<"first "<<n<<" chars are equal"<<endl;
                                else if(res>0)
                                        cout<<"1st string is greater in first "<<n<<" chars"<<endl;
                                else
                                        cout<<"2nd string is greater in first "<<n<<" chars"<<endl;
                                break;
                        }
                        case 14:
                                exit(0);
                        default:
                                cout<<"Invalid choice entered try again"<<endl;
                }
        }
        return 0;
}

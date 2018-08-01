#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int no_of_attributes=13;
long long int no_of_tweets=1000000;
struct tweet
{
    int account_age;
    long int no_of_followers;//
    long int no_of_following;//
    int no_of_lists;//
    int no_of_retweets;
    int no_of_hashtags;//
    int no_of_status;//
    int no_of_users_mentioned;//
    int no_of_urls;//
    int no_of_characters;//
    int no_of_digits;//
    int no_of_favourites;//
    bool verified;//
};
tweet a[1000000];
//long long int arr[1000000][no_of_attributes];
int getmonth(string s)
{
    string s1;

    typedef enum
    {
        Jan=1,
        Feb=2,
        Mar=3,
        Apr=4,
        May=5,
        Jun=6,
        Jul=7,
        Aug=8,
        Sep=9,
        Oct=10,
        Nov=11,
        Dec=12
        }str;


    int i;
    if(s=="Jan")return Jan;
    if(s=="Feb")return Feb;
    if(s=="Mar")return Mar;
    if(s=="Apr")return Apr;
    if(s=="May")return May;
    if(s=="Jun")return Jun;
    if(s=="Jul")return Jul;
    if(s=="Aug")return Aug;
    if(s=="Sep")return Sep;
    if(s=="Oct")return Oct;
    if(s=="Nov")return Nov;
    if(s=="Dec")return Dec;

}

int toint(string s)
{
    int n=0;
    while(s[n]!='\0')n++;
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>=48 && s[i]<=57)
        k=k*10+(s[i]-48);
        else return 0;

    }
    return k;
}
long long int get_account_age(string s11,string s12,string s13,string s21,string s22,string s23)
{
    int m1=getmonth(s11);
    int m2=getmonth(s21);
    string s1=s13,s2=s23;
    cout<<m1<<"  "<<m2<<endl;
    //cout<<toint(s1)<<"  "<<toint(s2)<<endl;
    long long int time1=0,time2=0,diff=0;
    time1=toint(s13)*10000+getmonth(s11)*100+toint(s12);
    time2=toint(s23)*10000+getmonth(s21)*100+toint(s22);
    //cout<<time1<<"  "<<time2<<endl;
    diff=time1-time2;

    return diff;

}
void get_array(long long int arr[][no_of_attributes])
{
    cout<<"START"<<endl;
        //ifstream fp("c50.txt");
    //ifstream fp("a1500 - Copy.txt");
    ifstream fp("new10000.txt");
    long long int count=0;
    long long int  created_at_present=0;
    long long int created_at_start=0;
    bool no_of_followers_done=0;//
    bool no_of_following_done=0;//
    bool no_of_lists_done=0;//
    bool no_of_tweets_done=0;
    bool no_of_retweets_done=0;
    bool no_of_status_done=0;//
    bool text_done=0;
    bool no_of_favourites_done=0;//
    bool verified_done=0;//

    string s1,s2,s3,s4,s5,s6,s7;
    while(!fp.eof())
    {
        char c;
        c=fp.get();

        //cout<<c<<endl;
        if(c=='"')
        {
            string s="";
            char ch;
            ch=fp.get();

            while(ch!='"')
            {
                if(ch=='\n')break;
                s+=ch;
                ch=fp.get();
            }
            //cout<<"yo \" found"<<s<<endl;

             if(s=="limit")
            {
                char chr;
                do
                {
                    chr=fp.get();
                }
                while(chr!='\n');
                //cout<<"limit"<<endl;
            }
            else if(s=="created_at")
            {
                //cout<<"fount ya "<<endl;
                if(created_at_present==0)
                {

                    fp>>s1;
                    fp>>s2;//month
                    fp>>s3;//date
                    fp>>s1>>s1;
                    fp.get();
                    for(int i=0;i<4;i++)
                    {
                        char c=fp.get();
                        s4+=c;
                    }
                    created_at_present=1;
                    //cout<<"fount yaiiiii "<<created_at_present<<endl;
                    fp.get();

                }
                else if(created_at_present==1 && created_at_start==0)
                {
                    //cout<<"found it yooooooo "<<endl;
                    fp>>s1;
                    fp>>s5;//month
                    fp>>s6;//date
                    fp>>s1>>s1;
                    fp.get();
                    for(int i=0;i<4;i++)
                    {
                        char c=fp.get();
                        s7+=c;
                    }
                    created_at_start=1;
                    //cout<<"found it yooooooo "<<created_at_start<<endl;
                    fp.get();
                }
                //cout<<created_at_present<<"        "<<created_at_start<<endl;
            }
            else if(s=="text" &&text_done==0)
            {
                char ch=fp.get();
                ch=fp.get();
                if(ch=='"')
                {

                    do{
                        ch=fp.get();
                        {
                            if((ch>=65&&ch<=90)||(ch>=97&&ch<=122))
                            {

                            }
                            if(ch>=48 && ch<=57)
                            {
                                a[count].no_of_digits++;

                            }
                            if(ch==35)
                            {
                                string s;
                                fp>>s;
                                a[count].no_of_hashtags++;
                            }
                            if(ch==64)
                            {
                                a[count].no_of_users_mentioned++;
                            }
                            if(ch=='\\')
                            {
                                ch=fp.get();
                                if(ch=='/')
                                {
                                    a[count].no_of_urls++;
                                    char chs;
                                    do
                                    {
                                        chs=fp.get();

                                    }
                                    while(chs!=' ');
                                }
                            }

                        }
                        a[count].no_of_characters++;
                        //cout<<ch;
                    }
                    while(ch!='"');

                }
                //cout<<"NO hashtags  "<<a[count].no_of_hashtags<<endl;
                //cout<<"NO users ment  "<<a[count].no_of_users_mentioned<<endl;
                //cout<<"NO characters  "<<a[count].no_of_characters<<endl;
                //cout<<"NO digits  "<<a[count].no_of_digits<<endl;
                //cout<<"NO urls "<<a[count].no_of_urls<<endl;
                text_done=1;

            }
            else if(s=="followers_count" && no_of_followers_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');
                //cout<<st<<endl;
                a[count].no_of_followers=toint(st);
                //cout<<"NO followers "<<a[count].no_of_followers<<endl;
                no_of_followers_done=1;

            }
            else if(s=="friends_count" &&no_of_following_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');


                a[count].no_of_following=toint(st);
                //cout<<"NO following"<<a[count].no_of_following<<endl;
                no_of_following_done=1;

            }
            else if(s=="listed_count" &&no_of_lists_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');


                a[count].no_of_lists=toint(st);
                //cout<<"NO lists"<<a[count].no_of_lists<<endl;
                no_of_lists_done=1;
            }
            else if(s=="favourites_count" &&no_of_favourites_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');
                a[count].no_of_favourites=toint(st);
                //cout<<"NO favourites"<<a[count].no_of_favourites<<endl;
                no_of_favourites_done=1;
            }
            else if(s=="statuses_count" && no_of_status_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');

                a[count].no_of_status=toint(st);
                //cout<<"NO statuses"<<a[count].no_of_status<<endl;
                no_of_status_done=1;
            }
            else if(s=="retweet_count" && no_of_retweets_done==0)
            {
                char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');

                a[count].no_of_retweets=toint(st);
                //cout<<"NO retweets"<<a[count].no_of_retweets<<endl;
                no_of_retweets_done=1;
            }

            else if(s=="verified" && verified_done==0)
            {
               char c;
                c=fp.get();

                string st="";
                do
                {

                    c=fp.get();
                    if(c!=',')
                        st+=c;
                }
                while(c!=',');

                if(st=="true")
                    a[count].verified=1;
                else
                    a[count].verified=0;
                //cout<<"is verified  "<<a[count].verified<<"  "<<st<<endl;
                verified_done=1;
            }
            /*else
            {
                cout<<"faltu                  "<<count<<"                "<<s<<endl;
            }*/

       }
       if(c=='\n')
       {

           //cout<<" linebreaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaak"<<endl<<endl<<endl<<endl<<endl;
           if(created_at_present ==1 && created_at_start==1)
           {

                a[count].account_age=get_account_age(s2,s3,s4,s5,s6,s7);
                //cout<<"account age "<<a[count].account_age<<" "<< s2<<" "<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<" "<<s7<<endl;
           }
           else
           {
            //cout<<"account age oo  "<<created_at_present<<"        "<<created_at_start<<endl;
           }
            count++;
            created_at_present=0;
            created_at_start=0;
            s4="";
            s7="";
            no_of_followers_done=0;//
             no_of_following_done=0;//
             no_of_lists_done=0;//
             no_of_tweets_done=0;
             no_of_retweets_done=0;
             no_of_status_done=0;//
             text_done=0;
             no_of_favourites_done=0;//
             verified_done=0;//
            //cout<<count<<endl<<endl;
            while(c=='\n')c=fp.get();
            //fp.get();
       }
    }
    for(long long int i=0;i<count;i++)
    {
        arr[i][0]=a[i].account_age;
        arr[i][1]=a[i].no_of_followers;//
        arr[i][2]=a[i].no_of_following;//
        arr[i][3]=a[i].no_of_lists;//
        arr[i][4]=a[i].no_of_retweets;
        arr[i][5]=a[i].no_of_hashtags;//
        arr[i][6]=a[i].no_of_status;//
        arr[i][7]=a[i].no_of_users_mentioned;//
        arr[i][8]=a[i].no_of_urls;//
        arr[i][9]=a[i].no_of_characters;//
        arr[i][10]=a[i].no_of_digits;//
        arr[i][11]=a[i].no_of_favourites;//
        arr[i][12]=a[i].verified;//
    }

}

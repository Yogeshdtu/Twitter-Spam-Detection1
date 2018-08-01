#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cmath>
#define MAX_INT 50000
const int k=8;
int diff_bw_2k=1;
int inetial_k=0;
int age_factor=5;
int gender_factor=10;
int age=1682;
int gender=1683;
int n=943;
//int n=943;
const int m=1682;
//int m=1684;
using namespace std;
int cluster[943];

int users[943][1682];
int dev_each_element[k][1000];
int ratings[943][1682];
double covariance[k][500][500];
double similarity[k][800];
double similarity_sum[k][800];
//int test[943][1682];
float new_avg[k][1682];
struct immediately_rated_movies
{
    int movie_no;
    int real_time_cluster_avg;

};
bool sort_arr(immediately_rated_movies lhs,immediately_rated_movies rhs)
{
    return lhs.real_time_cluster_avg>rhs.real_time_cluster_avg;
}

int main()
{

	ifstream fp("u.data");
	int i=0;
	int j=0;
	int r=0;

	long long  a;
	///*
	while(!fp.eof())
	{
		fp >> i;
		fp>>j;
		fp>>r;
		fp>>a;
		users[i-1][j-1]=r;
	}
	//*/




	int centroid[k];
	int ks[k][1682];
	vector<int > no_of_ele_in_cluster(k);
	int centroid_users=inetial_k;
	for(int i=0;i<k;i++)
	{
		centroid[i]=centroid_users;
		centroid_users+=diff_bw_2k;

	}
    int min_diff=MAX_INT;
	//clusturing the users on basis of min dist from the centroids

	for(int i=0;i<n;i++)
	{
		vector<float >diff(k);
		int belongs_to=0;
		min_diff=MAX_INT;
		for(int l=0;l<k;l++)
		{
			for(int j=0;j<m;j++)
			{
				//diff[l]+=abs(users[i][j]-users[centroid[l]][j]);
				float x=sqrt(abs(users[i][j]*users[i][j]-users[centroid[l]][j]*users[centroid[l]][j]));
				diff[l]+=x;
			}
		}
		//cout<<i<<" ";
		//for(int l=0;l<k;l++)
        //{
         //   cout<<diff[l]<<" ";
        //}

		for(int j=0;j<k;j++)
		{
			if(min_diff>diff[j])
			{
				min_diff=diff[j];
				belongs_to=j;
				cluster[i]=j;

			}
		}


		ks[belongs_to][no_of_ele_in_cluster[belongs_to]]=i;
		no_of_ele_in_cluster[belongs_to]++;
		//cout<<centroid[belongs_to]<<" "<<belongs_to<<" ";

        cout<<endl;
	}

 /*   for(int l=0;l<k;l++)
    {
		cout<<l<<"  ";
		for(int i=0;i<no_of_ele_in_cluster[i];i++)
		{
			cout<<diff[i]<<" ";
		}
		cout<<endl;
	}
*/
    //to print the elements in each cluster
//
/*
    cout<<endl<<endl;
    for(int l=0;l<k;l++)
	{
		cout<<centroid[l]<<"  ";
		for(int i=0;i<no_of_ele_in_cluster[l];i++)
		{
			cout<<ks[l][i]<<" ";
        }
		cout<<endl;
	}

//
*/
	//to calc the avg of each attribute in every cluster and finding the position
	//of the user which minimum difference with the avg

    cout<<endl;

	for(int i=0;i<k;i++)
	{
		float sum=0;

		for(int j=0;j<m;j++)
		{

		    sum=0;
			for(int l=0;l<no_of_ele_in_cluster[i];l++)
			{
				sum+=users[ks[i][l]][j];
			}
			new_avg[i][j]=sum/no_of_ele_in_cluster[i];
			//cout<<centroid[i]<< " "<<new_avg[i][j];
			//cout<<endl;
		}
       // cout<<avg[j]<<endl;



	}
    cout<<endl<<endl;
    float diff[k][2000];
    for(int i=0;i<k;i++)
    {

    for(int x=0;x<no_of_ele_in_cluster[i];x++)
		{
			for(int j=0;j<m;j++)
			{
			    if(float(users[ks[i][x]][j])>new_avg[i][j])
                    diff[i][x]+=(float(users[ks[i][x]][j])-new_avg[i][j]);
                else
                    diff[i][x]+=(new_avg[i][j]-float(users[ks[i][x]][j]));
				//cout<<centroid[i]<<" " <<x<<" "<<users[ks[i][x]][j]<<" "<<new_avg[i][j]<<" "<<diff[i][x]<<endl;
			}

		}
		//assigning the minimum position
		int min_diff=MAX_INT;
		int min_dist_posn=0;
		for(int x=0;x<no_of_ele_in_cluster[i];x++)
		{
			if(diff[i][x]<=min_diff)
			{
				min_diff=diff[i][x];
				min_dist_posn=x;
			}
		}
		centroid[i]=ks[i][min_dist_posn];
		//cout<<i<<" "<<centroid[i]<<" "<<endl;
    }
 /*   for(int l=0;l<k;l++)
	{
		cout<<centroid[l]<<"  ";
		for(int i=0;i<no_of_ele_in_cluster[l];i++)
		{
			cout<<ks[l][i]<<" ";
		}
		cout<<endl;
	}*/

//*/
	//finding the knee point dist bw previous cluster value
	//and current cluster value is minimum


	float new_diff[k][1000];
    float sum=0;
    int z=3;
    cout<<"ck"<<endl<<endl;

	while(z--)
    {

	for(int i=0;i<n;i++)
	{
		vector<float >diff(k);
		int belongs_to=10;
		min_diff=MAX_INT;
		for(int l=0;l<k;l++)
		{
			for(int j=0;j<m;j++)
			{
				//diff[l]+=abs(users[i][j]-users[centroid[l]][j]);
				float x=sqrt(abs(users[i][j]*users[i][j]-users[centroid[l]][j]*users[centroid[l]][j]));
				diff[l]+=x;
			}
		}
		//cout<<i<<" ";
		for(int l=0;l<k;l++)
        {
            //cout<<diff[l]<<" ";
        }

		for(int j=0;j<k;j++)
		{
			if(min_diff>diff[j])
			{
				min_diff=diff[j];
				belongs_to=j;
				cluster[i]=j;

			}
		}


		ks[belongs_to][no_of_ele_in_cluster[belongs_to]]=i;
		no_of_ele_in_cluster[belongs_to]++;
		//cout<<centroid[belongs_to]<<" "<<ks[belongs_to][no_of_ele_in_cluster[belongs_to]-1]<<" "<<belongs_to<<" ";

       // cout<<endl;
	}

    }

    for(int i=0;i<k;i++)
	{
		float sum=0;

		for(int j=0;j<m;j++)
		{

		    sum=0;
			for(int l=0;l<no_of_ele_in_cluster[i];l++)
			{
				sum+=users[ks[i][l]][j];
			}
			new_avg[i][j]=sum/no_of_ele_in_cluster[i];
			//cout<<centroid[i]<< " "<<new_avg[i][j];
			//cout<<endl;
		}
	//cout<<endl;
    }
   // for(int i=0;i<n;i++)
    //
//standard deviation
    float deviation=0;
    vector<float>deviation1(k);
    float sd1,sd2;

    float sd=0;
    for(int i=0;i<k;i++)
    {   deviation1[i]=0;
        for(int j=0;j<no_of_ele_in_cluster[i];j++)
        {
            for(int l=0;l<m;l++)
            {
                dev_each_element[i][j]+=abs((users[ks[i][j]][l]-new_avg[i][l])*(users[ks[i][j]][l]-new_avg[i][l]));
                deviation1[i]+=abs((users[ks[i][j]][l]-new_avg[i][l])*(users[ks[i][j]][l]-new_avg[i][l]));
            }
        }
        deviation+=sqrt(deviation1[i]/(no_of_ele_in_cluster[i]*m));
    }

    cout<<endl;
    sd=(deviation/(k));
    cout<<"Standard deviation = "<<sd<<endl;

    int k1=0;
    int k2=1;
    float mkd=0,mkad=0;
    for(int i=0;i<m;i++)
    {
            mkd+=abs(new_avg[k1][i]-new_avg[k2][i]);
    }
    mkad=mkd/m;
    float sq_sdk1=(deviation1[k1]/(no_of_ele_in_cluster[k1])*m);
    float sq_sdk2=(deviation1[k2]/(no_of_ele_in_cluster[k2]*m));

    float den=sqrt(abs((sq_sdk1)/((no_of_ele_in_cluster[k1])*m)+
                   ((sq_sdk2)/(no_of_ele_in_cluster[k2]))));

    float t_value=mkad/den;

    cout<<"t value = "<<t_value<<endl;
    float avg_mae[6];
    float avg_sd[6];
    float avg_tvalue[6];
    float avg_precesion[6];
    //float avg_sd[6];
    float counttest[6];

for(int p=0;p<6;p++)
{
    //deviation=0;
    ifstream fp2;
    //fp2.open("u1.test",ios::app);
///*
   if(p==0){fp2.open("u1.test",ios::app);}
   if(p==1){fp2.open("u2.test",ios::app);}
   if(p==2){fp2.open("u3.test",ios::app);}
   if(p==3){fp2.open("u4.test",ios::app);}
   if(p==4){fp2.open("u5.test",ios::app);}
   if(p==5){fp2.open("ua.test",ios::app);}
   if(p==6){fp2.open("ub.test",ios::app);}
//*/
	int i2=0;
	int j2=0;
	int r2=0;

	long long  int a2;
	float abs_error=0;
	float se=0;
	float mean_abs_error=0;
	float count=0;
	///*
	while(!fp2.eof())
	{
		fp2>>i2;
		fp2>>j2;
		fp2>>r2;
		fp2>>a2;
		float ki,kf=new_avg[cluster[i2-1]][j2-1];
//
/*
		if(ceil(kf)-kf>0.5)
        {
            ki=floor(kf);
        }
        else
        {
            ki=ceil(kf);
        }
//
*/
    //deviation+=(abs((r2-(new_avg[cluster[i2-1]][j2-1]))*(r2-(new_avg[cluster[i2-1]][j2-1]))));
    abs_error+=abs(r2-ceil(kf));
    se+=(r2-ceil(kf))*(r2-ceil(kf));
    count++;
	}
	fp2.close();
	counttest[p]=count;
	mean_abs_error=abs_error/count;
	cout<<endl<<abs_error<<" "<<count;
    cout<<endl<<endl<<"MAE = "<<mean_abs_error;
    //sd=sqrt(deviation/(count));
    // cout<<"Standard deviation = "<<sd<<" "<<deviation<<" "<<n*m<<endl;
    avg_mae[p]=mean_abs_error;
    //avg_sd[p]=sd;


    //cout<<endl<<endl<<" "<<deviation<<" "<<"standard deviation= "<<sd<<" "<<count<<" ";
    cout<<"done"<<p<<endl;
   }

    float TAE=0,MAE,TSD=0,MSD;
    for(int i=0;i<6;i++)
    {
         TAE+=avg_mae[i];

    }

    MAE=TAE/6;
    cout<<"Mean absolute error= " <<MAE<<endl;
    //MSD=TSD/6;
    //cout<<"Mean standard Deviation= " <<MSD<<endl;

    //test value

/*
//pearson equation

    for(int i=0;i<k;i++)
    {
        for(int j1=0;j1<no_of_ele_in_cluster[i];j1++)
        {
            double temp1=0;
            for(int j2=0;j2<no_of_ele_in_cluster[i];j2++)
            {
                for(int l=0;l<m;l++)
                {
                    temp1+=((users[ks[i][j1]][l]-new_avg[i][l])*(users[ks[i][j2]][l]-new_avg[i][l]));
                }
                double temp2=dev_each_element[i][j1];
                double temp3=dev_each_element[i][j2];

                double standard_dev_of_1st_ele=sqrt(dev_each_element[i][j1]/m);
                double standard_dev_of_2nd_ele=sqrt(dev_each_element[i][j2]/m);

                covariance[i][j1][j2]=temp1/(standard_dev_of_1st_ele*standard_dev_of_2nd_ele);
            }
        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j1=0;j1<no_of_ele_in_cluster[i];j1++)
        {
            double temp=0;
            double totalsim=0;
            for(int j2=0;j2<no_of_ele_in_cluster[i];j2++)
            {

                for(int l=0;l<m;l++)
                {
                      if(ratings[ks[i][j2]][l]!=0)
                        similarity[i][j1]+=covariance[i][j1][j2]*(new_avg[cluster[j2]][l]-ratings[ks[i][j2]][l]);

                }
                similarity_sum[i][j1]+=covariance[i][j1][j2];

            }

        }
    }

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<no_of_ele_in_cluster[i];j++)
        {
            for(int l=0;l<m;l++)
            {
                ratings[ks[i][j]][l]=new_avg[i][l]+similarity[i][j]/(no_of_ele_in_cluster[i]*similarity_sum[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ratings[i][j]<<"  ";
        }
    }
    */
    int exit;
    cout<<"hit 1 to view movies recommended to u else hit 0";
    cin>>exit;
    if(exit==1)
    {
        vector<int > real_time_ratings(m);
        int no_of_movies_to_rate;
        cout<<"Number of movies u want to rate= ";
        cin>>no_of_movies_to_rate;
        for(int i=0;i<no_of_movies_to_rate;i++)
        {
            int movie_no,rate;
            cin>>movie_no>>rate;
            real_time_ratings[movie_no-1]=rate;
        }

        float min_real_time_diff=MAX_INT;
        int real_time_belongs_to=0;
        for(int i=0;i<k;i++)
        {
            float real_time_diff=0;
            for(int l=0;l<m;l++)
            {
                real_time_diff+=abs(real_time_ratings[l]-new_avg[i][l]);
            }
            if(min_real_time_diff>real_time_diff)
            {
                min_real_time_diff=real_time_diff;
                real_time_belongs_to=i;
            }
        }


        immediately_rated_movies arr[m];
        for(int i=0;i<m;i++)
        {
            arr[i].movie_no=i;
            arr[i].real_time_cluster_avg=new_avg[real_time_belongs_to][i];
        }

        sort(arr,arr+m,sort_arr);
        for(int i=0;i<20;i++)
        {
            cout<<arr[i].movie_no<<endl;
        }




    }
	return 0;
}

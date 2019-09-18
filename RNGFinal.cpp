#include <iostream> 
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
//Number of trials
const int N = 200;

class Distribution
{
public:
	//Variables pertaining to the random number generator
	//Tracks distribution from 0 to 1 in .1 intervals
	int randdist [10] = {0};
	int randcount = 0;
	//Array for the x and y coordinates
	float xco [N] = {1.5};
	float yco [N] = {1.5};
	//Array for the movement in x and y directions
	float dist [N];
	//Array for the x and y direction needed to plot the graph correctly
	float distx [N];
	float disty [N];
	//Mean and standard deviation
	float mean;
	float std;
	void BoxMullerDistance();
	//Calculates mean and standard deviation
	void Calculate();
	//Prints out the results
	void Print();
};

void Distribution::BoxMullerDistance()
{
	//Generates numbers through uniform distribution with the range 0 to 1 with a seed of 1
	std::default_random_engine generator(1);
	std::uniform_real_distribution<float> distro(0.0,1.0);
	
	float x1;
	float x2;
	float y1;
	float y2;
	float u;
	float v;
	float distance;
	
	//Box Muller transformation
	int i = 0;
	while(i < N - 1)
	{
		do
		{
			x1 = 2.0 * distro(generator) - 1.0;
			if((x1 + 1) / 2 >= 0.0 && (x1 + 1) / 2 < 0.1)
			{
				randdist[0]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.1 && (x1 + 1) / 2 < 0.2)
			{
				randdist[1]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.2 && (x1 + 1) / 2 < 0.3)
			{
				randdist[2]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.3 && (x1 + 1) / 2 < 0.4)
			{
				randdist[3]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.4 && (x1 + 1) / 2 < 0.5)
			{
				randdist[4]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.5 && (x1 + 1) / 2 < 0.6)
			{
				randdist[5]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.6 && (x1 + 1) / 2 < 0.7)
			{
				randdist[6]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.7 && (x1 + 1) / 2 < 0.8)
			{
				randdist[7]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.8 && (x1 + 1) / 2 < 0.9)
			{
				randdist[8]++;
				randcount++;
			}
			else if((x1 + 1) / 2 >= 0.9 && (x1 + 1) / 2 <= 1.0)
			{
				randdist[9]++;
				randcount++;
			}
		
			x2 = 2.0 * distro(generator) - 1.0;
			if((x2 + 1) / 2 >= 0.0 && (x2 + 1) / 2 < 0.1)
			{
				randdist[0]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.1 && (x2 + 1) / 2 < 0.2)
			{
				randdist[1]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.2 && (x2 + 1) / 2 < 0.3)
			{
				randdist[2]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.3 && (x2 + 1) / 2 < 0.4)
			{
				randdist[3]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.4 && (x2 + 1) / 2 < 0.5)
			{
				randdist[4]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.5 && (x2 + 1) / 2 < 0.6)
			{
				randdist[5]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.6 && (x2 + 1) / 2 < 0.7)
			{
				randdist[6]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.7 && (x2 + 1) / 2 < 0.8)
			{
				randdist[7]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.8 && (x2 + 1) / 2 < 0.9)
			{
				randdist[8]++;
				randcount++;
			}
			else if((x2 + 1) / 2 >= 0.9 && (x2 + 1) / 2 <= 1.0)
			{
				randdist[9]++;
				randcount++;
			}
			u = x1 * x1 + x2 * x2;
		}while(u >= 1.0);
		
		v = sqrt((-2.0 * log(u))/u);
		
		distance = x1 * v;
		
		//Checks distance and new coordinates to make sure both are valid
		//Uses number generator to determine direction
		if(distance < 1 && distance > -1)
		{
			//X - Axis Movement
			if(distro(generator) > 0.5)
			{
				xco[i+1] = xco[i] + distance;
				yco[i+1] = yco[i];
				cout<<xco[0]<<endl;
				dist[i] = distance;
				distx[i] = distance;
				disty[i] = 0;
				if(xco[i+1] < 2 && xco[i+1] > -2)
				{
					i++;
				}	
			}
			//Y - Axis movement
			else
			{
				yco[i+1] = yco[i] + distance;
				xco[i+1] = xco[i];
				cout<<yco[0]<<endl;
				dist[i] = distance;
				disty[i] = distance;
				distx[i] = 0;
				if(yco[i+1] < 2 && yco[i+1] > -2)
				{
					i++;
				}				
			}
		}		
	}
}

void Distribution::Calculate()
{
	int i;
	int j;
	int k;
	
	float sum = 0;
	float square [N];
	float squaresum = 0;
	float var;
	
	for(i = 0; i < N; i++)
	{
		sum = sum + dist[i];
	}
	
	mean = sum / N;
	
	for(j = 0; j < N; j++)
	{
		square[j] = pow(dist[j] - mean,2);
		
	}
	
	for(k= 0; k < N; k++)
	{
		squaresum = square[k] + squaresum;
	}
	
	var = squaresum / N;
	
	std = sqrt(var);

}

void Distribution::Print()
{
	int i;
	int j;
	
	ofstream outco;
	ofstream outdist;
	ofstream outrng;
	
	//Stores the coordinates for plotting
	outco.open("rngco.dat");
	
	//Stores the distances generated
	outdist.open("rngresults.txt");
	
	//Stores the distribution of the random numbers
	outrng.open("rngdist.txt");
	
	//Precision set to five decimal places
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(5);
	
	outdist.setf(ios::showpoint);
	outdist.setf(ios::fixed);
	outdist.precision(5);
	
	outco.setf(ios::showpoint);
	outco.setf(ios::fixed);
	outco.precision(5);
	
	cout<<"		X		Y"<<endl;
	cout<<"Position"<<endl;
	outco<<"#	X	Y"<<endl;	
	outdist<<"	X	Y"<<endl;
	outco<<"#Positions"<<endl;
	for(i = 0; i < N; i++)
	{
		cout<<"Coordinates "<<i+1<<":	"<<xco[i]<<"		"<<yco[i]<<endl;
		outco<<xco[i]<<"		"<<yco[i]<<"		"<<distx[i]<<"		"<<disty[i]<<endl;
	}
	
	cout<<"Distance"<<endl;
	outdist<<"Distance"<<endl;
	for(j = 0; j < N; j++)
	{
		cout<<"Trial "<<j+1<<":	"<<dist[j]<<endl;
		outdist<<"Trial "<<j+1<<":	"<<dist[j]<<endl;
	}
	
	cout<<"Mean of X:"<<mean<<endl;
	cout<<"Standard deviation of X:"<<std<<endl;
	
	outdist<<"Mean of X:"<<mean<<endl;
	outdist<<"Standard deviation of X:"<<std<<endl;
	
	cout<<"Number of random numbers generated: "<<randcount<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0 and less than 0.1: "<<randdist[0]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.1 and less than 0.2: "<<randdist[1]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.2 and less than 0.3: "<<randdist[2]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.3 and less than 0.4: "<<randdist[3]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.4 and less than 0.5: "<<randdist[4]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.5 and less than 0.6: "<<randdist[5]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.6 and less than 0.7: "<<randdist[6]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.7 and less than 0.8: "<<randdist[7]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.8 and less than 0.9: "<<randdist[8]<<endl;
	cout<<"Number of times a value was generated equal to or greater than 0.9 and less than or equal to 1: "<<randdist[9]<<endl;
	
	outrng<<"Number of random numbers generated: "<<randcount<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0 and less than 0.1: "<<randdist[0]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.1 and less than 0.2: "<<randdist[1]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.2 and less than 0.3: "<<randdist[2]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.3 and less than 0.4: "<<randdist[3]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.4 and less than 0.5: "<<randdist[4]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.5 and less than 0.6: "<<randdist[5]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.6 and less than 0.7: "<<randdist[6]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.7 and less than 0.8: "<<randdist[7]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.8 and less than 0.9: "<<randdist[8]<<endl;
	outrng<<"Number of times a value was generated equal to or greater than 0.9 and less than or equal to 1: "<<randdist[9]<<endl;
	
	outco.close();
	outdist.close();
	outrng.close();
}

int main()
{
	Distribution Normal;
	
	Normal.BoxMullerDistance();
	Normal.Calculate();
	Normal.Print();

	return 0;
}
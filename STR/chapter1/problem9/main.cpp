#include "matrix.cpp"


int main()
{
	vector<vector<int> > imat ;
	vector<int> c1(4,1);c1[1]=0;
	imat.push_back(c1);
	vector<int>  c2(4,1);
	imat.push_back(c2);
	vector<int>  c3(4,1);c3[3]=0;
	imat.push_back(c3);
	matrix mat(imat);
       // mat.MaxSubMap();
	cout << "maximize sub matrix size is "<<mat.MaxSubMap()<<endl;
	return 0;
};

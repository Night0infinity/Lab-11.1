#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 11.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char fname[100];
			char gname[100];
			ofstream fout(fname, ios::binary);
			int n = 3;
			double* s = new double[n];
			s[0] = 4.;
			s[1] = -4.;
			s[2] = -9.3;
			for (unsigned i = 0; i < n; i++) {
				fout.write((char*)&s[i], sizeof(s[i]));
			}
			ProcessBIN(fname, gname);
			ifstream g(gname, ios::binary);
			Assert::AreEqual(s[0], -4.);


		}
	};
}

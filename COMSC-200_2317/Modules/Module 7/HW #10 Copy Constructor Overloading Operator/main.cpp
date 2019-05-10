#include <iostream>

using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores
{
private:
    string studentName;
    double * testScores; //points to array of test scores
    int numTestScore;
public:
    StudentTestScores(string name, int numScores)
    {
        studentName = name;
        numTestScore = numScores;
        testScores = new double[numTestScore];
        for (int i = 0; i < numTestScore; i++)
        {
            testScores[i] = DEFAULT_SCORE;
        }
    }

    StudentTestScores(const StudentTestScores &obj)
    {
      studentName = obj.studentName;
      numTestScore = obj.numTestScore;
      testScores = new double[numTestScore];
      for (int i = 0; i < numTestScore; i++)
      {
          testScores[i] = obj.testScores[i];
      }
    }

    ~StudentTestScores()
    {
        delete [] testScores;
    }
    void setName(string name)
    {
        studentName = name;
        return;
    }

    string getName()
    {
        return studentName;
    }

    void setTestScore(double score, int index)
    {
        testScores[index] = score;
        return;
    }
    double getTestScore(int index)
    {
        return testScores[index];
    }

    void dispalyNameNAllScores()
    {
        cout << getName() << endl;
        for (int i = 0; i < numTestScore; i++)
        {
            cout << getTestScore(i) << "  ";
        }
    }

    bool operator > (const StudentTestScores &a)
    {
      int aScore = 0;
      int thisScore = 0;
      for (int i = 0; i < a.numTestScore; i++)
      {
        aScore = aScore + a.testScores[i];
      }
      for (int i = 0; i < this->numTestScore; i++)
      {
        thisScore = thisScore + this->testScores[i];
      }

      aScore = aScore / a.numTestScore;
      thisScore = thisScore / this->numTestScore;

      if (aScore < thisScore) return true;
      else return false;
    }
};

int main()
{
  StudentTestScores sts1("John", 3);
  sts1.setTestScore(70, 0);
  sts1.setTestScore(80, 1);
  sts1.setTestScore(90, 2);

  cout << endl << "Display 1st student -- 1st run" << endl;
  sts1.dispalyNameNAllScores();

  StudentTestScores sts2 = sts1;

  cout << endl << endl << "Display 2nd student -- 1st run" << endl;
  sts2.dispalyNameNAllScores();

  sts2.setName("Mary");
  sts2.setTestScore(100, 2);
  cout << endl << endl << "The name of 2nd student has been changed to Mary and the 3rd score has been changed to 100.";

  cout << endl << endl << "Display 1st student -- 2nd run" << endl;
  sts1.dispalyNameNAllScores();
  cout << endl << endl << "Display 2nd student -- 2nd run" << endl;
  sts2.dispalyNameNAllScores();

   StudentTestScores sts3(sts1);
   sts3.setTestScore(99, 2);
   cout << endl << "Display 1st student -- 3rd run" << endl;
   sts1.dispalyNameNAllScores();
   cout << endl << "Display 3rd student -- 3rd run" << endl;
   sts3.dispalyNameNAllScores();


   if (sts2 > sts1) cout << endl << "The average score of sts2 is higher than that of sts1" << endl << endl;
   else cout << endl << "The average score of sts2 is lower than or equal to that of sts1" << endl << endl;

   return 0;
}

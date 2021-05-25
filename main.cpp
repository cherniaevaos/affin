#include <iostream>
#include <cmath>

using namespace std;
//Аффинный шифр
int main() {
    const short N = 26;
    string str;
    short i=0, x, a=5, b=8;
    bool Check = true, Choice;

    cout <<"Input text (A..Z): ";
    getline (cin, str);
    cout << "If you want to encrypt the text input (0), else input (1): ";
    cin >> Choice;
    cout << "Output: ";

 switch (Choice){
     case 0:
    //Шифрование
          while ((i+1 <= str.length()) && (Check == true)) {

              x = (int) str[i];

              //Проверка на то, что буквы в тексте принадлежат мн-ву (A..Z)
              if (x == 32)  {
                  cout <<" ";
              } else if ( (x < 91) && (x > 64) ) {
                  x -= 65;
                  x =(x * a + b) % N;
                  x += 65;
                  cout << (char) x ;
              } else {
                  cout << "Error!!";
                  Check = false;
              }i++;
          }
          break;
          case 1:

            //Дешифровка
              a = N - a;
              while ((i+1 <= str.length()) && (Check == true)) {

                  x = (int) str[i];

                  //Проверка на то, что буквы в тексте принадлежат мн-ву (A..Z)
                  if (x == 32)  {
                      cout <<" ";
                  } else if ( (x < 91) && (x > 64) ) {
                      x -= 65;
                      x = (a * (x + N - b))% N;
                      x += 65;
                      cout << (char) x ;
                  } else {
                      cout << "Error!!";
                      Check = false;
                  }i++;
              }break;
       }
    return 0;
}

// // #include <iostream>
// // using namespace std;
// // void swap(int *s1, int *s2)
// // {
// //     int *s3;
// //    s3=s1;
// //    s2=s1;
// //    s2=s3;

// // }
// // int main()
// // {
// //     // cout << "Enter first number: " << endl;
// //     // int n1=0;
// //     // cin >> n1;
// //     // cout << "Enter second number: " << endl;
// //     // int n2=0;
// //     // cin >> n2;
// //     int n1=9;
// //     int n2= 7;
// //     int *x=NULL;
// //     int *y=NULL;
// //     x=&n1;
// //     y=&n2;
// //     cout<<"x and y before swapping: "<<*x<<*y<<endl;

// //     swap(x, y);
// //     cout<<" After swapping x a y: "<<n1<<n2<<endl;

// // }

// #include <iostream>
// using namespace std;
// int main()
// {
//     string s;
//     cout << "Enter a string: " << endl;
//     cin >> s;

//     int choice = 0;
//     while (choice != 3)
//     {
//         cout << "Enter 1 to check if a string is palindrome: " << endl;
//         cout << "Enter 2 to check frequency of a certain character: " << endl;
//         cout << "Enter 3 to exit: " << endl;
//         cin >> choice;

//         if (choice == 1)
//         {
//             char *ptr = &s[0];
//             // ptr=s;
//             int size = s.size();
//             char *ptr2 = &s[size - 1];
//             int flag = 0;
//             while (ptr < ptr2)
//             {
//                 if (*ptr != *ptr2)
//                 {
//                     flag = 1;
//                     break;
//                 }
//                 ptr++;
//                 ptr--;
//             }
//             if (flag == 0)
//             {
//                 cout << "String is a palindrome: " << endl;
//             }
//             else
//                 cout << "String is not a palindrome" << endl;
//         }
//         else if (choice == 2)
//         {
//             cout << "Enter the character to check frequency: " << endl;
//             char ch;
//             cin >> ch;
//             int count = 0;
//             char *ptr = &s[0];
//             for (int i = 0; i < s.size(); i++)
//             {
//                 if (ch == *ptr)
//                 {
//                     count++;
//                 }
//                 ptr++;
//             }
//             cout << "Frequency of " << ch << " is " << count << endl;
//         }
//     }
// }

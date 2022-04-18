// Task 5.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "vector"
#include <iostream>
#include "algorithm"
#include <functional>

int random(int n) {
    return rand() % n;
}

bool is_simple(int x) {

    if (x < 3) { return false; }

    for (int i = 2; i < x / 2.0; i++) {
        if (x % i == 0) { return false; };
    }
    return true;
}

int main()
{
    std::vector <int> vec;
    int temp = 0;
    for (int i = 0; i < 10; i++) {    //1
        vec.push_back(rand());
    }

    std::cout << "Insert numbers" << std::endl;

    for (int i = 0; i < 4; i++) {  //2
        std::cin >> temp;
        vec.push_back(temp);
    }

    std::cout << "Init mass: " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });
    
    std::random_shuffle(vec.begin(), vec.end(), std::pointer_to_unary_function<int, int>(random));   //3
    std::vector<int>::iterator ip;
    std::cout << std::endl << "Shuffled mass: " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });

    ip = std::unique(vec.begin(), vec.end());

    vec.resize(std::distance(vec.begin(), ip));   //4

    std::cout << std::endl << "Unique mass: " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });
    
    int count_of_number = 0;  //5

    std::for_each(vec.begin(), vec.end(), [&](int x) {if (x % 2 != 0) { count_of_number += 1; }});

    std::cout <<std::endl << "Count of nechet numbers: " << count_of_number << std::endl; //6
    
    auto elem = std::find_if(vec.begin(), vec.end(), is_simple); //!!!!!!!!!!!!!!!!
    
    
    if (elem != vec.end()) {
        std::cout << "Simple number is: " << *elem << std::endl;    //7
    }
    else {
        std::cout << "No simple number" << std::endl;
    }

    std::for_each(vec.begin(), vec.end(), [](int x) {return x * x; });

    std::vector<int> vec_2;

    for (int i = 0; i < vec.size(); i++) {
        vec_2.push_back(rand());
    }

    int summ_elem = 0;

    std::for_each(vec_2.begin(), vec_2.end(), [&](int x) {summ_elem += x; });

    std::cout << "Summ of elements: " << summ_elem << std::endl;    //8

    std::fill(vec_2.begin(), vec_2.begin() + 2, 1);   //9

    std::cout << std::endl << "replacing with 1 mass: " << std::endl;
    std::for_each(vec_2.begin(), vec_2.end(), [](int x) {std::cout << x << " "; });

    std::vector<int> vec_3; //!!!!!
    for (int i = 0; i < vec_2.size(); i++) {
        vec_3.push_back(vec_2[i] - vec[i]);
    }


    std::cout << std::endl << "divided mass: " << std::endl;  //10
    std::for_each(vec_3.begin(), vec_3.end(), [](int x) {std::cout << x << " "; });

    auto temp_func = [](int x) {return x < 0;};
    std::replace_if(vec_3.begin(), vec_3.end(), temp_func, 0);
    std::cout << std::endl << "replace with zero mass: " << std::endl; //11
    std::for_each(vec_3.begin(), vec_3.end(), [](int x) {std::cout << x << " "; });

    
    std::remove(vec_3.begin(), vec_3.end(), 0);
    std::cout << std::endl << "no zero mass: " << std::endl; //12
    std::for_each(vec_3.begin(), vec_3.end(), [](int x) {std::cout << x << " "; });


    std::reverse(vec_3.begin(), vec_3.end());
    std::cout << std::endl << "reversed mass: " << std::endl; //13
    std::for_each(vec_3.begin(), vec_3.end(), [](int x) {std::cout << x << " "; });

    int max_elem;
    std::vector <int> result;
    std::cout << std::endl << "Top 3 elem" << std::endl;  //14
    std::vector<int> vec_3_copy;

    for (int i = 0; i < vec_3.size(); i++)
        vec_3_copy.push_back(vec_3[i]);
   
    for (int i = 0; i < 3; i++) {
        max_elem = *std::max_element(vec_3.begin(), vec_3.end());
        std::cout << "Top " << i + 1 << ": " << max_elem << std::endl;
        std::remove(vec_3.begin(), vec_3.end(), max_elem);
    }

    std::sort(vec.begin(), vec.end());
    std::sort(vec_2.begin(), vec_2.end());

    std::cout << std::endl << "sorted 1st mass: " << std::endl; //15
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });

    std::cout << std::endl << "sorted 2nd mass: " << std::endl; //15
    std::for_each(vec_2.begin(), vec_2.end(), [](int x) {std::cout << x << " "; });

    std::vector<int> vec_4;

    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        vec_4.push_back(*iter);
    }

    for (auto iter = vec_2.begin(); iter != vec_2.end(); iter++) {
        vec_4.push_back(*iter);
    }

    std::cout << std::endl << "merged mass: " << std::endl; //15
    std::for_each(vec_4.begin(), vec_4.end(), [](int x) {std::cout << x << " "; });


    std::cout << std::endl << "1st sequence" << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });

    std::cout << std::endl << "2nd sequence" << std::endl;
    std::for_each(vec_2.begin(), vec_2.end(), [](int x) {std::cout << x << " "; });

    std::cout << std::endl << "3d sequence" << std::endl;
    std::for_each(vec_3_copy.begin(), vec_3_copy.end(), [](int x) {std::cout << x << " "; });

    std::cout << std::endl << "4th sequence" << std::endl;
    std::for_each(vec_4.begin(), vec_4.end(), [](int x) {std::cout << x << " "; });
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

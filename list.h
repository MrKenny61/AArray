#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <assert.h>
#include <QString>
#include <QStringList>


using namespace std;
typedef string datatype;

bool is_digits(const datatype &str)
{
    return str.find_first_not_of("0123456789") == datatype::npos;
}


class liststr
{
private:
	struct node {
		datatype key, value;
		node*next, *prev;
	};

	node *first, *last;

    void delete_liststr()
	{
		while (first != last)
		{
			if (first == nullptr) return;
			node *t = first;
			first = first->next;
			delete t;
		}
		delete last;
		first = nullptr;
		last = nullptr;
	}

	
public:
    liststr()
	{
		first = last = nullptr;
	}
    liststr &operator=(const liststr &p)
	{
        delete_liststr();
        copy_liststr(p.first, p.last);
		return *this;
	}

    void copy_liststr(node *from_first, node *from_last)
	{
		first = nullptr;
		last = nullptr;
		node **to = &first;
		const node *from = from_first;
		while (from != from_last->next)
		{
			node *prev = *to;
			*to = new node;
			(*to)->prev = prev;
			(*to)->key = prev->key;
			(*to)->value = prev->value;
			to = &(*to)->next;
			from = from->next;
		}
		*to = nullptr;
		last = *to;
	}
    void push_back(const datatype &k, const datatype &v)
	{
		if (last == nullptr)
		{
			last = new node;
			last->prev = nullptr;
			first = last;
		}
		else
		{
			last->next = new node;
			last->next->prev = last;
			last = last->next;
		}
		last->key = k;
		last->value = v;
		last->next = nullptr;
	}

    friend std::istream &operator>>(std::istream &is, liststr&p)
	{
        datatype k, v;

        while ( is >> k && is >> v )
		{
			p.push_back(k, v);
		}
		is.clear();
		return is;
	}
    friend std::ostream &operator<<(std::ostream &os, liststr &l)
	{
		node * f = l.first;
		if (f == nullptr)return os << " ";
		while (f->next != nullptr)
		{
            os << "(" << f->key<< ":" << f->value << ")" << std::endl;
			f = f->next;
		}
		os << "(" << f->key << ":" << f->value << ")" << std::endl;
		return os;
	}

	bool key_is(const datatype &k)
	{
		node* f = first;
		while (f != nullptr)
		{
			if (f->key == k)
				return true;
			f = f->next;
		}
		return false;
	}

    size_t size() const
	{
		size_t elem = 0;
		node* f = first;
		while (f!=last)
		{
			elem++;
			f = f->next;
		}
		return elem + 1;
	}

    friend void delete_elem(datatype const&key,liststr&l)
	{
		node*p = l.first;
		while (p && p->key != key)
		{
			p = p->next;
		}
		if (!p)
			return;
		if (p != l.first && p->next)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		else if (p == l.first)
		{
			p->next->prev = nullptr;
			l.first = p->next;
		}
		else
			p->prev->next = nullptr;
		delete p;
	}

	datatype operator[](datatype key)
	{
		if (key_is(key))
		{
			node*p = first;
			while (p->key != key)
				p = p->next;
			return p->value;
		}
        return "error";
	}

    liststr &operator=( liststr l1)
    {
        copy_liststr(first, l1.first);
        return *this;
    }

	void sort()
	{
		node*p = first;
        if (is_digits(p->key))
        {
	
	
		while (p->next)
		{
			if (p->key > p->next->key)
			{
				datatype f = p->next->key;
				datatype f1 = p->next->value;
				p->next->key = p->key;
				p->next->value = p->value;
				p->key = f;
				p->value = f1;
				sort();
			}
			else
				p = p->next;
		}
		}
		else
		{
		while (p->next)
		{
	
			if (strcmp(p->key.c_str(), p->next->key.c_str()) < 0)
			{
				datatype f = p->next->key;
				datatype f1 = p->next->value;
				p->next->key = p->key;
				p->next->value = p->value;
				p->key = f;
				p->value = f1;
				sort();
			}
			else
				p = p->next;
		}
	}
	}


    string Total()
    {
        string s = "";
        node * f = first;
        if (f == nullptr)return s;
        while (f->next != nullptr)
        {
            s += f->key + ":" + f->value+ " ";
            f = f->next;
        }
        s += f->key + ":" + f->value;
        return s;
    }



    ~liststr()
	{
        delete_liststr();
	}
};

datatype delete_space(datatype s)
{
    s.erase(unique_copy(s.begin(), s.end(), s.begin(), [](char c1, char c2) {return c1 == ' ' && c2 == ' '; }),s.end());
    return s;
}


datatype read_lines(const string path)
{
    ifstream f;
    f.open(path);

    assert(f.is_open());

    datatype s;
    datatype s1;
    while(f)
    {
        getline(f,s);
        s1 += s;
        s1 += " ";
    }
    s1.erase(s1.length() - 1);

    f.close();

    return s1;
}


liststr massive(const string path){
    string s =read_lines(path);
    QString qs = QString::fromStdString(s);
    QStringList qsl = qs.split(' ', QString::SkipEmptyParts);
    qsl.sort();

    liststr a;
    for(int i = 1; i < qsl.size();i++)
    {
        int k = 1;
        string s1 = qsl[i-1].toStdString();
        while(i<qsl.size() && qsl[i-1] == qsl[i]){
            k++;
            i++;
        }

        a.push_back(s1,to_string(k));
    }
    return a;
}




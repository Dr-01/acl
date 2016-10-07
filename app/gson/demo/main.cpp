#include "stdafx.h"
#include <list>
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include "struct.h"
#include "gson.h"
#include "gsoner.h"

void test_base()
{
	base b;
	b.a = 1;
	b.a_ptr = new int(1);
	b.acl_string = "a";
	b.acl_string_ptr = new acl::string("a");
	b.string = "b";
	b.string_ptr = new std::string("b");
	b.b = 2;
	b.b_ptr = new unsigned int( 2);
	b.c = 3;
	b.c_ptr = new int64_t(3);
	b.d = 4;
	b.d_ptr = new unsigned long(4);
	b.e = 5;
	b.e_ptr = new unsigned long long(5);
	b.f = 6;
	b.f_ptr = new long(6);
	b.g = 7;
	b.g_ptr = new long long(7);
	b.h = 9;
	b.h_ptr = new float(9);
	b.i = 10;
	b.i_ptr = new double(9);

	list1 obj;
	obj.b = b;
	obj.b_ptr = new base(b);
	obj.bases_list.push_back(b);
	obj.bases_list_ptr = new std::list<base>;
	obj.bases_list_ptr->push_back(b);
	obj.bases_ptr_list_ptr = new std::list<base*>;
	obj.bases_ptr_list_ptr->push_back(new base(b));

	acl::json json;
	acl::json_node &node = acl::gson::gson(json, obj);
	printf("%s\n", node.to_string().c_str());


	list1 obj2;
	acl::json json2;
	json2.update(node.to_string().c_str());
	printf("%s\n",json2.to_string().c_str());
	std::pair<bool,std::string> ret = acl::gson::gson(json2.get_root(), obj2);
	if(ret.first == false)
		printf("%s\n",ret.second.c_str());

	acl::json json3;
	acl::json_node &node3 = acl::gson::gson(json3, obj);
	printf("%s\n", node3.to_string().c_str());
}
void test02()
{
	acl::gson::gsoner gr;
	gr.read_file("struct2.h");
	gr.parse_code();
}

void test04()
{
	acl::gson::gsoner gr;

	gr.read_multi_file({"struct.h" });
	gr.parse_code();
	gr.gen_gson();
}

int main(void)
{
	//test_vector();
	test_base();
	return 0;
	std::string str = "std::string";
	std::string sub = str.substr(str.find("::"));
	printf("%s",sub.c_str());
	getchar();
	//test01();
	return 0;
	printf("enter any key to exit\r\n");
	return 0;
}

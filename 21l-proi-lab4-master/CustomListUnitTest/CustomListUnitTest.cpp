#include "CppUnitTest.h"
#include "../CustomList/CustomList.h"
#include "../CustomList/Person.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomListUnitTest
{
	TEST_CLASS(CustomListUnitTest)
	{
	public:
		//	Node tests
		TEST_METHOD(create_char_node) {
			Node<char> node;
		}
		TEST_METHOD(create_person_node) {
			Node<Person> node;
		}
		TEST_METHOD(node_get_value) {
			Node<char> node('a', false);
			Assert::AreEqual('a', node.get_value());
		}
		TEST_METHOD(node_get_isZero) {
			Node<char> node('a', false);
			Assert::AreEqual(false, node.get_isZero());
		}
		TEST_METHOD(node_operator_equal) {
			Node<char> node1('a', false);
			Node<char> node2;
			node2 = node1;
			Assert::AreEqual('a', node2.get_value());
		}
		//	Person tests
		TEST_METHOD(create_person) {
			Person person;
		}
		TEST_METHOD(create_person_with_name) {
			Person person("Jack");
		}
		TEST_METHOD(person_get_name) {
			Person person("Jack");
			std::string expected = "Jack";
			Assert::AreEqual(expected, person.get_name());
		}
		
		TEST_METHOD(person_operator_equal) {
			Person person1("Jack");
			Person person2("Adam");
			person1 = person2;
			Assert::IsTrue(person1 == person2);
		}
		TEST_METHOD(person_operator_less_than) {
			Person person1("abc");
			Person person2("abd");
			Assert::IsTrue(person1 < person2);
		}
		TEST_METHOD(person_operator_is_equal_to_person) {
			Person person1("Jack");
			Person person2("Jack");
			Person person3("Adam");
			Assert::IsTrue(person1 == person2);
			Assert::IsFalse(person1 == person3);
		}
		TEST_METHOD(person_operator_is_equal_to_bool) {
			Person person1;
			Person person2("Jack");
			Assert::IsTrue(person1 == false);
			Assert::IsTrue(person2 == true);
		}
		TEST_METHOD(person_operator_not_equal_to_boool) {
			Person person1;
			Person person2("Jack");
			Assert::IsTrue(person1 != true);
			Assert::IsTrue(person2 != false);
		}
		//	List tests
		TEST_METHOD(create_char_list_with_default_size)
		{
			List<char> mylist;
			Assert::AreEqual(10, mylist.size());
		}
		TEST_METHOD(create_person_list_with_default_size) {
			List<Person> mylist;
			Assert::AreEqual(10, mylist.size());
		}
		TEST_METHOD(create_char_list_with_given_size) {
			List<char, 2> list;
			Assert::AreEqual(2, list.size());
		}
		TEST_METHOD(create_person_list_with_given_size) {
			List<Person, 2> list;
			Assert::AreEqual(2, list.size());
		}
		TEST_METHOD(char_list_insert) {
			List<char> list;
			list.insert(0, 'a');
		}
		TEST_METHOD(person_list_insert) {
			List<Person> list;
			Person person("Jack");
			list.insert(3, person);
		}
		TEST_METHOD(char_list_operator_brackets) {
			List<char> list;
			list.insert(0, 'a');
			Assert::AreEqual('a', list[0]);
		}
		TEST_METHOD(person_list_operator_brackets) {
			List<Person> list;
			Person person("Jack");
			list.insert(3, person);
			Assert::IsTrue(person == list[3]);
		}
		TEST_METHOD(char_list_remove) {
			List<char> list;
			list.insert(3, 'a');
			Assert::AreEqual('a', list[3]);
			list.remove(3);
			Assert::IsFalse(list[3]);
		}
		TEST_METHOD(person_list_remove) {
			List<Person> list;
			Person person("Jack");
			list.insert(3, person);
			Assert::IsTrue(person == list[3]);
			list.remove(3);
			Assert::IsTrue(list[3] == false);
		}
		TEST_METHOD(char_list_clear) {
			List<char> list;
			list.insert(1, 'a');
			list.insert(2, 'b');
			list.insert(3, 'b');
			Assert::AreEqual('a', list[1]);
			Assert::AreEqual('b', list[2]);
			Assert::AreEqual('b', list[3]);
			list.clear();
			for (int i = 0; i < list.size(); ++i) {
				Assert::IsFalse(list[i]);
			}
		}
		TEST_METHOD(person_list_clear) {
			List<Person> list;
			Person person1("Jack");
			Person person2("Michael");
			Person person3("Jane");
			list.insert(0, person1);
			list.insert(1, person2);
			list.insert(2, person3);
			Assert::IsTrue(person1 == list[0]);
			Assert::IsTrue(person2 == list[1]);
			Assert::IsTrue(person3 == list[2]);
			list.clear();
			for (int i = 0; i < list.size(); ++i) {
				Assert::IsTrue(list[i] == false);
			}
		}
		TEST_METHOD(char_list_get_array) {
			List<char> list;
			for (int i = 0; i < list.size(); ++i) {
				list.insert(i, 'a');
				Assert::IsTrue(list[i] == list.getArray()[i]);
			}
		}
		TEST_METHOD(person_list_get_array) {
			List<Person> list;
			Person person("Jack");
			for (int i = 0; i < list.size(); ++i) {
				list.insert(i, person);
				Assert::IsTrue(list[i] == list.getArray()[i]);
			}
		}
		// SortedList tests
		TEST_METHOD(char_sorted_list_push) {
			SortedList<char> list;
			list.push('b');
			Assert::AreEqual('b', list[0]);
			list.push('a');
			list.push('a');
			Assert::AreEqual('a', list[0]);
			Assert::AreEqual('b', list[1]);
			Assert::IsFalse(list[3]);
		}
		TEST_METHOD(person_sorted_list_push) {
			SortedList<Person> list;
			Person person1("Michael");
			Person person2("Adam");
			Person person3("Michael");
			list.push(person1);
			list.push(person2);
			list.push(person3);
			Assert::IsTrue(person2 == list[0]);
			Assert::IsTrue(person1 == list[1]);
			Assert::IsTrue(list[2] == false);
		}
	};
}

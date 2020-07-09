class Person:
    __name = "J. Doe"
    __age = "18"

    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    def set_name(self, name):
        self.__name = name

    def get_name(self) -> str:
        return self.__name

    def set_age(self, age):
        self.__age = age

    def get_age(self) -> int:
        return self.__age

    def print_info(self):
        print("PERSON INFO:")
        print("Name: "+self.__name)
        print("Age: "+str(self.__age))


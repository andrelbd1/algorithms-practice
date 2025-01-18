class LazySingleton:

    __instance = None

    def __init__(self):
        if not LazySingleton.__instance:
            print("__init__ method called")
        else:
            print("Instance already created:", self.getInstance())

    @classmethod
    def getInstance(cls):
        if not cls.__instance:
            cls.__instance = LazySingleton()

        return cls.__instance


if __name__ == "__main__":
    s = LazySingleton()
    print("Object create", LazySingleton.getInstance())

    s1 = LazySingleton()

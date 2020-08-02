
class Customer:
    def __init__(self, customerId:int, fName:str, lName:str, ph:str):
        self.customerId = customerId
        self.firstName = fName
        self.lastName = lName
        self.phone = ph
        pass

    def __str__(self):
        pass     

class Flight:
    def __init__(self, flightNo:str, orig:str, dest:str, mSeats:int):
        self.flightNumber = flightNo
        self.origin = orig
        self.destination = dest
        self.passengerList = []
        self.masSeats = mSeats
        self.numPassengers = 0
        pass

    def addPassenger(self, cust:Customer, ):
        return 0

    def findPassenger(self, custId:int):
        return 0

    def removePassenger(self, custId:int):
        return 0
    
    def getPassengerList(self):

        return self.passengerList


def menu():
    print("1. Add Customer")
    print("2. Add flight")
    print("3. Add Booking")
    print("4. View flights")
    print("5. View Customer")
    print("6. View Flight")
    print("7. Exit")

if __name__ == "__main__":
    print("Fsfs")
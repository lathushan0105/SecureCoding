import datetime

class Order:
    def __init__(self, customer, date_placed, total_cost, list_of_items, ship_to, status):
        self.customer = customer
        self.date_placed = date_placed
        self.total_cost = total_cost
        self.list_of_items = list_of_items
        self.ship_to = ship_to
        self.status = status

    def print_order(self):
        print("Customer: " + self.customer)
        print("Date placed: " + str(self.date_placed.date()))
        print("Cost: $" + str(self.total_cost))
        print("Items: " + self.list_of_items)
        print("Ship to: " + self.ship_to)
        print("Status: " + self.status)

# All orders are stored in this dictionary
orders = {}

def DisplayOrder(order_id):
    if order_id in orders:
        print("Details for the order " + order_id + ":")
        orders[order_id].print_order()
    else:
        print("Order " + order_id + " was not found.")

# Simulating the scenario
o1 = Order("Jane Doe", datetime.datetime(2023, 5, 17), 21.69, "Ann Patchett, Dutch House", "100 Old Owl Crst, Red Deer AB, A0B 1C2", "Delivered")
o2 = Order("Peter Parker", datetime.datetime(2023, 6, 9), 16.94, "John Grisham, The Firm", "296 Caroline St W, Halifax NS, D3E 4F5", "Delivered")
o3 = Order("Cindy Zhao", datetime.datetime(2023, 12, 9), 23.89, "Nancy Gordon, Knitting for Beginners", "123 Taylor St S, Brampton ON, G6H 7I8", "In Progress")

orders.update({1 : o1})
orders.update({2 : o2})
orders.update({3 : o3})

# Assume that the user Jane Doe is properly authenticated.
# They submit the following request:

DisplayOrder(1)

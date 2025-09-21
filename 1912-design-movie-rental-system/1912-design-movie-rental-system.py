class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
         self.unrented = collections.defaultdict(SortedList);
         self.rented = SortedList();
         self.pricemap = {};

         for shop, movies, price in entries:
            self.unrented[movies].add((price,shop));
            self.pricemap[(shop,movies)] = price;


    def search(self, movie: int) -> List[int]:
        ans = [];
        i = 0;
        for price, shop in self.unrented[movie]:
            if i > 5: break;
            ans.append(shop);
        return ans;
    def rent(self, shop: int, movie: int) -> None:
        price = self.pricemap[(shop,movie)];
        self.rented.add((price,shop,movie));
        self.unrented[movie].remove((price,shop));

    def drop(self, shop: int, movie: int) -> None:
        price = self.pricemap[(shop,movie)];
        self.rented.remove((price,shop,movie));
        self.unrented[movie].add((price,shop));

    def report(self) -> List[List[int]]:
        ans = [];
        i = 0
        for price, shop, movie in self.rented:
            if i > 5: break;
            ans.append((shop,movie));
        return ans;

# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()
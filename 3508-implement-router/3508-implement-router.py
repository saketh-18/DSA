class Router:
    def __init__(self, memoryLimit: int):
        self.queue = collections.deque();
        self.dest = collections.defaultdict(SortedList);
        self.limit = memoryLimit
        self.fastlookup = collections.defaultdict(int);


    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        if(self.fastlookup[(source,destination,timestamp)] == 0):
            if len(self.queue) >= self.limit:
                old_src, old_dest, old_time = self.queue.popleft();
                self.fastlookup[(old_src,old_dest,old_time)] = 0;
                self.dest[old_dest].remove(old_time);

            self.fastlookup[(source,destination,timestamp)] = 1;
            self.dest[destination].add(timestamp);
            self.queue.append((source,destination,timestamp));
            return True;
        # self.queue.remove((source,destination,timestamp));
        # self.dest[destination].remove(timestamp);
        return False;

    def forwardPacket(self) -> List[int]:
        if len(self.queue) > 0:
            source, destination, timestamp = self.queue[0];
            self.fastlookup[(source,destination,timestamp)] = 0;
            self.dest[destination].remove(timestamp);
            return self.queue.popleft();
        return [];

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        return self.dest[destination].bisect_right(endTime) - self.dest[destination].bisect_left(startTime);

# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)
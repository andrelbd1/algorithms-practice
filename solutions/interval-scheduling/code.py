# Interval Scheduling
from operator import attrgetter

def indexSort(arr, indices): #Sorting
    for col in reversed(indices):
        arr.sort(key = itemgetter(col))
    return arr

def company(arrive, dur): #Company
    return [arrive,     # start time
            arrive+dur, # finish time
            dur]        # duration


def maxEvents(arrival, duration):
    companies=[]
    for i in range(0,len(arrival)): #Make company 
        companies.append(company(arrival[i],duration[i]))

    companies = indexSort(companies, [1]) #Sorting by finish time

    schedule=[]
    schedule.append(companies[0]) #Adding the first company in the schedule
    
    for i in range(1,len(companies)):
        conflict=False
        for j in range(len(schedule)): #Verify overlap
            # Verify whether company arrival overlaps someone already scheduled
            if (companies[i][0] >= schedule[j][0]) & (companies[i][0] < schedule[j][1]):
                conflict=True
                break
            # Verify whether company end overlaps someone already scheduled
            if (companies[i][1] > schedule[j][0]) & (companies[i][1] < schedule[j][1]):
                conflict=True
                break
            # Verify whether company start and end overlaps someone already scheduled
            if (companies[i][0] < schedule[j][0]) & (companies[i][1] > schedule[j][1]):
                conflict=True
                break
        # If there is no overlap, the company is scheduled
        if conflict==False:
            schedule.append(companies[i])
    
    # print(schedule)
    print(len(schedule))
    return len(schedule)


#Input Samples
# Input 1
arrival=[1,3,3,5,7]
duration=[2,2,1,2,1]
maxEvents(arrival,duration)
print("")

# Input 2
arrival=[1, 1, 1, 1, 4]
duration=[10, 3, 6, 4, 2]
maxEvents(arrival,duration)
print("")

# Input 3
arrival=[948, 386, 218, 273, 540, 248, 386, 497, 886, 624, 421, 145, 969, 736, 916, 626, 535, 43, 12, 680, 153, 245, 296]
duration=[819, 397, 693, 816, 992, 34, 670, 398, 554, 548, 826, 211, 663, 212, 809, 378, 762, 626, 336, 869, 996, 777, 768]
maxEvents(arrival,duration)
print("")

# Input 4
arrival=[875, 332, 557, 302, 873, 561, 95, 985, 756, 790, 408, 16, 194, 770, 681, 456, 856, 507, 964, 503, 677, 109, 250, 332, 845, 639, 809]
duration=[998, 652, 850, 204, 732, 532, 15, 420, 776, 10, 181, 930, 224, 55, 261, 738, 546, 318, 526, 201, 257, 565, 598, 649, 705, 551, 151]
maxEvents(arrival,duration)
print("")

# Input 5
arrival= [790, 95, 770, 809, 408, 503, 302, 194, 677, 681, 507, 985, 964, 561, 856, 639, 109, 250, 332, 332, 845, 873, 456, 756, 557, 16, 875]
duration=[10, 15, 55, 151, 181, 201, 204, 224, 257, 261, 318, 420, 526, 532, 546, 551, 565, 598, 649, 652, 705, 732, 738, 776, 850, 930, 998]
maxEvents(arrival,duration)
print("")
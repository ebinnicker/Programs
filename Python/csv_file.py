import csv
    
name  = []
freq = []
year = []
male = True
female = False

user = input('> ') 
while user != 'quit()':
    file = open('TX.csv')
    rows = csv.DictReader(file)    
    years = list(user.split())
    year_rg = list(range(int(years[0]), (int(years[1])+1)))
    for r in rows:
        if male == True:
            if (int(r['Year']) in year_rg) and (r['Gender'] == 'M'):
                if r['Name'] in name:
                    spot = name.index(r['Name'])
                    freq[spot] = freq[spot]+ int(r['Freq'])
                else:
                    name.append(r['Name'])
                    freq.append(int(r['Freq']))
        if female == True:
            if (int(r['Year']) in year_rg) and (r['Gender'] == 'F'):
                if r['Name'] in name:
                    spot = name.index(r['Name'])
                    freq[spot] = freq[spot]+ int(r['Freq'])
                else:
                    name.append(r['Name'])
                    freq.append(int(r['Freq']))
                
    i = 1
    while i < 6:
        largest = max(freq)
        locate = freq.index(largest)
        nm = name[locate]
        print('%d: %s (%d)' %(i,nm,largest))
        freq.remove(largest)
        name.remove(name[locate])
        i+=1
    file.close()
    
    file = open('TX.csv')
    rows = csv.DictReader(file)     
    user = input('> ')
    if user == 'girl': 
        user = input('> ')        
        years = list(user.split())
        year_rg = list(range(int(years[0]), (int(years[1])+1)))        
        name = []
        freq = []
        for r in rows:
            if (int(r['Year']) in year_rg) and (r['Gender'] == 'F'):
                if r['Name'] in name:
                    spot = name.index(r['Name'])
                    freq[spot] = freq[spot]+ int(r['Freq'])
                else:
                    name.append(r['Name'])
                    freq.append(int(r['Freq']))
        i = 1
        while i < 6:
            largest = max(freq)
            locate = freq.index(largest)
            nm = name[locate]
            print('%d: %s (%d)' %(i,nm,largest))
            freq.remove(largest)
            name.remove(name[locate])
            i+=1            
        female = True
        male = False
        user = input('> ')
    if user == 'boy':
        user = input('> ')
        years = list(user.split())
        year_rg = list(range(int(years[0]), (int(years[1])+1)))        
        name = []
        freq = []
        for r in rows:
            if (int(r['Year']) in year_rg) and (r['Gender'] == 'M'):
                if r['Name'] in name:
                    spot = name.index(r['Name'])
                    freq[spot] = freq[spot]+ int(r['Freq'])
                else:
                    name.append(r['Name'])
                    freq.append(int(r['Freq']))
        i = 1
        while i < 6:
            largest = max(freq)
            locate = freq.index(largest)
            nm = name[locate]
            print('%d: %s (%d)' %(i,nm,largest))
            freq.remove(largest)
            name.remove(name[locate])
            i+=1            
        female = False
        male = True
        user = input('> ')
    file.close()


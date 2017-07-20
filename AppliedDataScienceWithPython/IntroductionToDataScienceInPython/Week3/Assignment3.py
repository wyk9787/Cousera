
# coding: utf-8

# ---
#
# _You are currently looking at **version 1.5** of this notebook. To download notebooks and datafiles, as well as get help on Jupyter notebooks in the Coursera platform, visit the [Jupyter Notebook FAQ](https://www.coursera.org/learn/python-data-analysis/resources/0dhYG) course resource._
#
# ---

# # Assignment 3 - More Pandas
# This assignment requires more individual learning then the last one did - you are encouraged to check out the [pandas documentation](http://pandas.pydata.org/pandas-docs/stable/) to find functions or methods you might not have used yet, or ask questions on [Stack Overflow](http://stackoverflow.com/) and tag them as pandas and python related. And of course, the discussion forums are open for interaction with your peers and the course staff.

# ### Question 1 (20%)
# Load the energy data from the file `Energy Indicators.xls`, which is a list of indicators of [energy supply and renewable electricity production](Energy%20Indicators.xls) from the [United Nations](http://unstats.un.org/unsd/environment/excel_file_tables/2013/Energy%20Indicators.xls) for the year 2013, and should be put into a DataFrame with the variable name of **energy**.
#
# Keep in mind that this is an Excel file, and not a comma separated values file. Also, make sure to exclude the footer and header information from the datafile. The first two columns are unneccessary, so you should get rid of them, and you should change the column labels so that the columns are:
#
# `['Country', 'Energy Supply', 'Energy Supply per Capita', '% Renewable']`
#
# Convert `Energy Supply` to gigajoules (there are 1,000,000 gigajoules in a petajoule). For all countries which have missing data (e.g. data with "...") make sure this is reflected as `np.NaN` values.
#
# Rename the following list of countries (for use in later questions):
#
# ```"Republic of Korea": "South Korea",
# "United States of America": "United States",
# "United Kingdom of Great Britain and Northern Ireland": "United Kingdom",
# "China, Hong Kong Special Administrative Region": "Hong Kong"```
#
# There are also several countries with numbers and/or parenthesis in their name. Be sure to remove these,
#
# e.g.
#
# `'Bolivia (Plurinational State of)'` should be `'Bolivia'`,
#
# `'Switzerland17'` should be `'Switzerland'`.
#
# <br>
#
# Next, load the GDP data from the file `world_bank.csv`, which is a csv containing countries' GDP from 1960 to 2015 from [World Bank](http://data.worldbank.org/indicator/NY.GDP.MKTP.CD). Call this DataFrame **GDP**.
#
# Make sure to skip the header, and rename the following list of countries:
#
# ```"Korea, Rep.": "South Korea",
# "Iran, Islamic Rep.": "Iran",
# "Hong Kong SAR, China": "Hong Kong"```
#
# <br>
#
# Finally, load the [Sciamgo Journal and Country Rank data for Energy Engineering and Power Technology](http://www.scimagojr.com/countryrank.php?category=2102) from the file `scimagojr-3.xlsx`, which ranks countries based on their journal contributions in the aforementioned area. Call this DataFrame **ScimEn**.
#
# Join the three datasets: GDP, Energy, and ScimEn into a new dataset (using the intersection of country names). Use only the last 10 years (2006-2015) of GDP data and only the top 15 countries by Scimagojr 'Rank' (Rank 1 through 15).
#
# The index of this DataFrame should be the name of the country, and the columns should be ['Rank', 'Documents', 'Citable documents', 'Citations', 'Self-citations',
#        'Citations per document', 'H index', 'Energy Supply',
#        'Energy Supply per Capita', '% Renewable', '2006', '2007', '2008',
#        '2009', '2010', '2011', '2012', '2013', '2014', '2015'].
#
# *This function should return a DataFrame with 20 columns and 15 entries.*

# In[2]:

import pandas as pd
import numpy as np

def answer_one():
    #load first xls file
    energy = pd.read_excel('Energy Indicators.xls', usecols=range(2, 6), skiprows=15, skipfooter=38)
    energy.columns = ['Country', 'Energy Supply', 'Energy Supply per Capita', '% Renewable']
    energy = energy.drop([0, 1])
    energy = energy.replace('...', np.NaN)
    energy['Energy Supply'] *= 1000000
    original_names = ['Republic of Korea', 'United States of America20', 'United Kingdom of Great Britain and Northern Ireland19', 'China, Hong Kong Special Administrative Region3', 'Australia1', 'Bolivia (Plurinational State of)', 'China2', 'China, Macao Special Administrative Region4', 'Denmark5', 'Falkland Islands (Malvinas)', 'France6', 'Switzerland17', 'Japan10', 'Spain16', 'Iran (Islamic Republic of)', 'Italy9']
    new_names = ['South Korea', 'United States', 'United Kingdom', 'Hong Kong', 'Australia', 'Bolivia', 'China', 'Macao', 'Denmark', 'Falkland Islands', 'France', 'Switzerland', 'Japan', 'Spain', 'Iran', 'Italy']
    energy['Country'] = energy['Country'].replace(original_names, new_names)

    #load second csv file
    GDP = pd.read_csv('world_bank.csv', skiprows=4)
    original_names = ['Korea, Rep.', 'Iran, Islamic Rep.', 'Hong Kong SAR, China']
    new_names = ['South Korea', 'Iran', 'Hong Kong']
    GDP['Country Name'] = GDP['Country Name'].replace(original_names, new_names)

    #load last xlsx file
    ScimEn = pd.read_excel('scimagojr-3.xlsx')

    #join them together
    answer = pd.merge(ScimEn, energy, how='inner', left_on='Country', right_on='Country')
    answer = pd.merge(answer, GDP, how='inner', left_on='Country', right_on='Country Name')
    answer = answer [['Country', 'Rank', 'Documents', 'Citable documents', 'Citations', 'Self-citations', 'Citations per document', 'H index', 'Energy Supply', 'Energy Supply per Capita', '% Renewable', '2006', '2007', '2008', '2009', '2010', '2011', '2012', '2013', '2014', '2015']]
    answer = answer.set_index('Country')
    answer = answer[:15]

    return answer
answer_one()


# ### Question 2 (6.6%)
# The previous question joined three datasets then reduced this to just the top 15 entries. When you joined the datasets, but before you reduced this to the top 15 items, how many entries did you lose?
#
# *This function should return a single number.*

# In[3]:

# get_ipython().run_cell_magic('HTML', '', '<svg width="800" height="300">\n  <circle cx="150" cy="180" r="80" fill-opacity="0.2" stroke="black" stroke-width="2" fill="blue" />\n  <circle cx="200" cy="100" r="80" fill-opacity="0.2" stroke="black" stroke-width="2" fill="red" />\n  <circle cx="100" cy="100" r="80" fill-opacity="0.2" stroke="black" stroke-width="2" fill="green" />\n  <line x1="150" y1="125" x2="300" y2="150" stroke="black" stroke-width="2" fill="black" stroke-dasharray="5,3"/>\n  <text  x="300" y="165" font-family="Verdana" font-size="35">Everything but this!</text>\n</svg>')


# In[4]:

def answer_two():
    #load first xls file
    energy = pd.read_excel('Energy Indicators.xls', usecols=range(2, 6), skiprows=15, skipfooter=38)
    energy.columns = ['Country', 'Energy Supply', 'Energy Supply per Capita', '% Renewable']
    energy = energy.drop([0, 1])
    energy = energy.replace('...', np.NaN)
    energy['Energy Supply'] *= 1000000
    original_names = ['Republic of Korea', 'United States of America20', 'United Kingdom of Great Britain and Northern Ireland19', 'China, Hong Kong Special Administrative Region3', 'Australia1', 'Bolivia (Plurinational State of)', 'China2', 'China, Macao Special Administrative Region4', 'Denmark5', 'Falkland Islands (Malvinas)', 'France6', 'Switzerland17', 'Japan10', 'Spain16', 'Iran (Islamic Republic of)', 'Italy9', 'Greenland7', 'Indonesia8', 'Kuwait11', 'Netherlands12', 'Portugal13', 'Saudi Arabia14', 'Serbia15', 'Ukraine18', 'Micronesia (Federated States of)', 'Sint Maarten (Dutch part)', 'Venezuela (Bolivarian Republic of)']
    new_names = ['South Korea', 'United States', 'United Kingdom', 'Hong Kong', 'Australia', 'Bolivia', 'China', 'China, Macao Special Administrative Region', 'Denmark', 'Falkland Islands', 'France', 'Switzerland', 'Japan', 'Spain', 'Iran', 'Italy', 'Greenland', 'Indonesia', 'Kuwait', 'Netherlands', 'Portugal', 'Saudi Arabia', 'Serbia', 'Ukraine', 'Micronesia', 'Sint Maarten', 'Venezuela']
    energy['Country'] = energy['Country'].replace(original_names, new_names)

    #load second csv file
    GDP = pd.read_csv('world_bank.csv', skiprows=4)
    original_names = ['Korea, Rep.', 'Iran, Islamic Rep.', 'Hong Kong SAR, China']
    new_names = ['South Korea', 'Iran', 'Hong Kong']
    GDP['Country Name'] = GDP['Country Name'].replace(original_names, new_names)
    GDP = GDP.rename(columns={'Country Name': 'Country'})

    #load last xlsx file
    ScimEn = pd.read_excel('scimagojr-3.xlsx')

    #join them together
    answer = pd.merge(ScimEn, energy, how='inner', left_on='Country', right_on='Country')
    answer = pd.merge(answer, GDP, how='inner', left_on='Country', right_on='Country')
    intersect_count = len(answer.index)
    answer1 = pd.merge(ScimEn, energy, how='outer', left_on='Country', right_on='Country')
    answer1 = pd.merge(answer1, GDP, how='outer', left_on='Country', right_on='Country')
    union_count = len(answer1.index)

    return union_count - intersect_count

answer_two()


# In[ ]:




# <br>
#
# Answer the following questions in the context of only the top 15 countries by Scimagojr Rank (aka the DataFrame returned by `answer_one()`)

# ### Question 3 (6.6%)
# What is the average GDP over the last 10 years for each country? (exclude missing values from this calculation.)
#
# *This function should return a Series named `avgGDP` with 15 countries and their average GDP sorted in descending order.*

# In[30]:

def answer_three():
    Top15 = answer_one()
    ans = Top15[['2006', '2007', '2008', '2009', '2010', '2011', '2012', '2013', '2014', '2015']]
    ans = ans.apply(pd.DataFrame.mean, axis=1)
    ans = ans.sort_values(ascending=False)
    ans = ans.rename('avgGDP')
    return ans
answer_three()


# ### Question 4 (6.6%)
# By how much had the GDP changed over the 10 year span for the country with the 6th largest average GDP?
#
# *This function should return a single number.*

# In[42]:

def answer_four():
    Top15 = answer_one()
    country = answer_three().reset_index().iloc[5].iloc[0]
    ans = Top15.loc[country]['2015'] - Top15.loc[country]['2006']
    return ans
answer_four()


# ### Question 5 (6.6%)
# What is the mean `Energy Supply per Capita`?
#
# *This function should return a single number.*

# In[48]:

def answer_five():
    Top15 = answer_one()
    return Top15['Energy Supply per Capita'].mean()
answer_five()


# ### Question 6 (6.6%)
# What country has the maximum % Renewable and what is the percentage?
#
# *This function should return a tuple with the name of the country and the percentage.*

# In[65]:

def answer_six():
    Top15 = answer_one()
    max_percent = Top15['% Renewable'].max()
    country = Top15[Top15['% Renewable'] == max_percent].index.tolist()[0]
    return country, max_percent
answer_six()


# ### Question 7 (6.6%)
# Create a new column that is the ratio of Self-Citations to Total Citations.
# What is the maximum value for this new column, and what country has the highest ratio?
#
# *This function should return a tuple with the name of the country and the ratio.*

# In[68]:

def answer_seven():
    Top15 = answer_one()
    Top15['Ratio'] = Top15['Self-citations'] / Top15['Citations']
    max_ratio = Top15['Ratio'].max()
    country = Top15[Top15['Ratio'] == max_ratio].index.tolist()[0]
    return country, max_ratio
answer_seven()


# ### Question 8 (6.6%)
#
# Create a column that estimates the population using Energy Supply and Energy Supply per capita.
# What is the third most populous country according to this estimate?
#
# *This function should return a single string value.*

# In[76]:

def answer_eight():
    Top15 = answer_one()
    Top15['Population']= Top15['Energy Supply'] / Top15['Energy Supply per Capita']
    third_populous = Top15['Population'].nlargest(3)
    country = third_populous.index.tolist()[2]
    return country
answer_eight()


# ### Question 9 (6.6%)
# Create a column that estimates the number of citable documents per person.
# What is the correlation between the number of citable documents per capita and the energy supply per capita? Use the `.corr()` method, (Pearson's correlation).
#
# *This function should return a single number.*
#
# *(Optional: Use the built-in function `plot9()` to visualize the relationship between Energy Supply per Capita vs. Citable docs per Capita)*

# In[82]:

def answer_nine():
    Top15 = answer_one()
    Top15['PopEst'] = Top15['Energy Supply'] / Top15['Energy Supply per Capita']
    Top15['Citable docs per Capita'] = Top15['Citable documents'] / Top15['PopEst']
    return Top15['Citable docs per Capita'].corr(Top15['Energy Supply per Capita'])
answer_nine()


# In[79]:

def plot9():
    import matplotlib as plt
    get_ipython().magic('matplotlib inline')

    Top15 = answer_one()
    Top15['PopEst'] = Top15['Energy Supply'] / Top15['Energy Supply per Capita']
    Top15['Citable docs per Capita'] = Top15['Citable documents'] / Top15['PopEst']
    Top15.plot(x='Citable docs per Capita', y='Energy Supply per Capita', kind='scatter', xlim=[0, 0.0006])
# plot9()


# In[ ]:

#plot9() # Be sure to comment out plot9() before submitting the assignment!


# ### Question 10 (6.6%)
# Create a new column with a 1 if the country's % Renewable value is at or above the median for all countries in the top 15, and a 0 if the country's % Renewable value is below the median.
#
# *This function should return a series named `HighRenew` whose index is the country name sorted in ascending order of rank.*

# In[14]:

def answer_ten():
    Top15 = answer_one()
    median = Top15['% Renewable'].median()
    Top15['Status'] = Top15['% Renewable'] >= median
    ans = pd.Series(name='HighRenew')
    for country in Top15.index:
        if(Top15.loc[country]['Status'] == True):
            ans = ans.append(pd.Series(1, index=[country]))
        else:
            ans = ans.append(pd.Series(0, index=[country]))
    return ans
answer_ten()


# ### Question 11 (6.6%)
# Use the following dictionary to group the Countries by Continent, then create a dateframe that displays the sample size (the number of countries in each continent bin), and the sum, mean, and std deviation for the estimated population of each country.
#
# ```python
# ContinentDict  = {'China':'Asia',
#                   'United States':'North America',
#                   'Japan':'Asia',
#                   'United Kingdom':'Europe',
#                   'Russian Federation':'Europe',
#                   'Canada':'North America',
#                   'Germany':'Europe',
#                   'India':'Asia',
#                   'France':'Europe',
#                   'South Korea':'Asia',
#                   'Italy':'Europe',
#                   'Spain':'Europe',
#                   'Iran':'Asia',
#                   'Australia':'Australia',
#                   'Brazil':'South America'}
# ```
#
# *This function should return a DataFrame with index named Continent `['Asia', 'Australia', 'Europe', 'North America', 'South America']` and columns `['size', 'sum', 'mean', 'std']`*

# In[52]:

def answer_eleven():
    Top15 = answer_one()
    Top15['PopEst'] = Top15['Energy Supply'] / Top15['Energy Supply per Capita']
    ContinentDict  = {'China':'Asia',
                  'United States':'North America',
                  'Japan':'Asia',
                  'United Kingdom':'Europe',
                  'Russian Federation':'Europe',
                  'Canada':'North America',
                  'Germany':'Europe',
                  'India':'Asia',
                  'France':'Europe',
                  'South Korea':'Asia',
                  'Italy':'Europe',
                  'Spain':'Europe',
                  'Iran':'Asia',
                  'Australia':'Australia',
                  'Brazil':'South America'}
    ans = pd.DataFrame(index=range(5))
    index = []
    size_lst = []
    sum_lst = []
    mean_lst = []
    std_lst = []
    for group, frame in Top15.groupby(ContinentDict):
        size = frame['PopEst'].count()
        pop_sum = frame['PopEst'].sum()
        mean = frame['PopEst'].mean()
        std = frame['PopEst'].std()
        index.append(group)
        size_lst.append(size)
        sum_lst.append(pop_sum)
        mean_lst.append(mean)
        std_lst.append(std)
#         data = pd.Series([size, pop_sum, mean, std], index=[group])
    ans.index = index
    ans['size'] = size_lst
    ans['sum'] = sum_lst
    ans['mean'] = mean_lst
    ans['std'] = std_lst
    ans.index.name = 'Continent'
    return ans

answer_eleven()


# ### Question 12 (6.6%)
# Cut % Renewable into 5 bins. Group Top15 by the Continent, as well as these new % Renewable bins. How many countries are in each of these groups?
#
# *This function should return a __Series__ with a MultiIndex of `Continent`, then the bins for `% Renewable`. Do not include groups with no countries.*

# In[108]:

def cut_off(item):
    max_val = 69.65
    min_val = 2.28
    diff = max_val - min_val
    if item < min_val + diff / 5:
        return 0
    elif item < min_val + diff * 2 / 5:
        return 1
    elif item < min_val + diff * 3 / 5:
        return 2
    elif item < min_val + diff * 4 / 5:
        return 3
    else:
        return 4

def answer_twelve():
    ContinentDict  = {'China':'Asia',
                  'United States':'North America',
                  'Japan':'Asia',
                  'United Kingdom':'Europe',
                  'Russian Federation':'Europe',
                  'Canada':'North America',
                  'Germany':'Europe',
                  'India':'Asia',
                  'France':'Europe',
                  'South Korea':'Asia',
                  'Italy':'Europe',
                  'Spain':'Europe',
                  'Iran':'Asia',
                  'Australia':'Australia',
                  'Brazil':'South America'}
    Top15 = answer_one()
#     max_val = Top15['% Renewablegroup_'].max()
    #     min_val = Top15['% Renewable'].min()
    continent_index = []
    group_index = []
    size = []
    for group, frame in Top15.groupby(ContinentDict):
        frame = frame.reset_index().set_index('% Renewable')
        for group2, frame2 in frame.groupby(cut_off):
            group_index.append(group2)
            continent_index.append(group)
            size.append(len(frame2))
    ans = pd.Series(size, index=[continent_index, group_index])
    return ans

answer_twelve()


# ### Question 13 (6.6%)
# Convert the Population Estimate series to a string with thousands separator (using commas). Do not round the results.
#
# e.g. 317615384.61538464 -> 317,615,384.61538464
#
# *This function should return a Series `PopEst` whose index is the country name and whose values are the population estimate string.*

# In[158]:

def seperate(num):
#     lst = []
#     decimal = str(num).split('.')
#     real = (int)(decimal[0])
#     while real > 0:
#         lst.append(real % 1000)
#         real = (int)(real/1000)
#     real_str = ""
#     for i in reversed(lst):
#         i = str(i)
#         while len(i) < 3:
#             i += '0'
#         real_str += str(i) + ","
#     real_str = real_str[:-1]
#     if len(decimal) == 2:
#         return real_str + "." + decimal[1]
#     else:
#         return real_str
    return "{:,}".format(num)


def answer_thirteen():
    Top15 = answer_one()
    Top15['PopEst'] = Top15['Energy Supply'] / Top15['Energy Supply per Capita']
    Top15 = Top15.reset_index()
    ans = Top15['PopEst'].apply(seperate)
    ans.index = Top15['Country']
    return ans

answer_thirteen()


# ### Optional
#
# Use the built in function `plot_optional()` to see an example visualization.

# In[146]:

def plot_optional():
    import matplotlib as plt
    get_ipython().magic('matplotlib inline')
    Top15 = answer_one()
    ax = Top15.plot(x='Rank', y='% Renewable', kind='scatter',
                    c=['#e41a1c','#377eb8','#e41a1c','#4daf4a','#4daf4a','#377eb8','#4daf4a','#e41a1c',
                       '#4daf4a','#e41a1c','#4daf4a','#4daf4a','#e41a1c','#dede00','#ff7f00'],
                    xticks=range(1,16), s=6*Top15['2014']/10**10, alpha=.75, figsize=[16,6]);

    for i, txt in enumerate(Top15.index):
        ax.annotate(txt, [Top15['Rank'][i], Top15['% Renewable'][i]], ha='center')

    print("This is an example of a visualization that can be created to help understand the data. This is a bubble chart showing % Renewable vs. Rank. The size of the bubble corresponds to the countries' 2014 GDP, and the color corresponds to the continent.")


# In[147]:

# plot_optional() # Be sure to comment out plot_optional() before submitting the assignment!

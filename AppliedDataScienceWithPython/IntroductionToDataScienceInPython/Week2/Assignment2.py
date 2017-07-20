
# coding: utf-8

# ---
#
# _You are currently looking at **version 1.2** of this notebook. To download notebooks and datafiles, as well as get help on Jupyter notebooks in the Coursera platform, visit the [Jupyter Notebook FAQ](https://www.coursera.org/learn/python-data-analysis/resources/0dhYG) course resource._
#
# ---

# # Assignment 2 - Pandas Introduction
# All questions are weighted the same in this assignment.
# ## Part 1
# The following code loads the olympics dataset (olympics.csv), which was derrived from the Wikipedia entry on [All Time Olympic Games Medals](https://en.wikipedia.org/wiki/All-time_Olympic_Games_medal_table), and does some basic data cleaning.
#
# The columns are organized as # of Summer games, Summer medals, # of Winter games, Winter medals, total # number of games, total # of medals. Use this dataset to answer the questions below.

# In[4]:
import pandas as pd

def print_full(x):
    pd.set_option('display.max_rows', len(x))
    print(x)
    pd.reset_option('display.max_rows')

df = pd.read_csv('olympics.csv', index_col=0, skiprows=1)

for col in df.columns:
    if col[:2]=='01':
        df.rename(columns={col:'Gold'+col[4:]}, inplace=True)
    if col[:2]=='02':
        df.rename(columns={col:'Silver'+col[4:]}, inplace=True)
    if col[:2]=='03':
        df.rename(columns={col:'Bronze'+col[4:]}, inplace=True)
    if col[:1]=='№':
        df.rename(columns={col:'#'+col[1:]}, inplace=True)

names_ids = df.index.str.split('\s\(') # split the index by '('

df.index = names_ids.str[0] # the [0] element is the country name (new index)
df['ID'] = names_ids.str[1].str[:3] # the [1] element is the abbreviation or ID (take first 3 characters from that)
df = df.drop('Totals')



# ### Question 0 (Example)
#
# What is the first country in df?
#
# *This function should return a Series.*

# In[2]:

# You should write your whole answer within the function provided. The autograder will call
# this function and compare the return value against the correct solution value
def answer_zero():
    # This function returns the row for Afghanistan, which is a Series object. The assignment
    # question description will tell you the general format the autograder is expecting
    return df.iloc[0]

# You can examine what your function returns by calling it in the cell. If you have questions
# about the assignment formats, check out the discussion forums for any FAQs
answer_zero()


# ### Question 1
# Which country has won the most gold medals in summer games?
#
# *This function should return a single string value.*

# In[19]:

def answer_one():
    max_val = max(df['Gold'])
    max_country = df[df['Gold'] == max_val].index[0]
    return max_country
answer_one()


# ### Question 2
# Which country had the biggest difference between their summer and winter gold medal counts?
#
# *This function should return a single string value.*

# In[45]:

def answer_two():
    max_val = max(abs(df['Gold']-df['Gold.1']))
    max_country = df[df['Gold']-df['Gold.1'] == max_val].index[0]
    return max_country

answer_two()


# ### Question 3
# Which country has the biggest difference between their summer gold medal counts and winter gold medal counts relative to their total gold medal count?
#
# $$\frac{Summer~Gold - Winter~Gold}{Total~Gold}$$
#
# Only include countries that have won at least 1 gold in both summer and winter.
#
# *This function should return a single string value.*

# In[65]:

def answer_three():
    df_gold = df[(df['Gold'] >= 1) & (df['Gold.1'] >=1)]
    max_val = max((df_gold['Gold']-df_gold['Gold.1'])/(df_gold['Gold']+df_gold['Gold.1']))
    max_country = df_gold[(df_gold['Gold']-df_gold['Gold.1'])/(df_gold['Gold']+df_gold['Gold.1']) == max_val].index[0]
    return max_country

answer_three()


# ### Question 4
# Write a function that creates a Series called "Points" which is a weighted value where each gold medal (`Gold.2`) counts for 3 points, silver medals (`Silver.2`) for 2 points, and bronze medals (`Bronze.2`) for 1 point. The function should return only the column (a Series object) which you created.
#
# *This function should return a Series named `Points` of length 146*

# In[68]:

def answer_four():
    data = df['Gold.2']*3 + df['Silver.2']*2 + df['Bronze.2']
    return pd.Series(data, index=df.index)
answer_four()


# ## Part 2
# For the next set of questions, we will be using census data from the [United States Census Bureau](http://www.census.gov/popest/data/counties/totals/2015/CO-EST2015-alldata.html). Counties are political and geographic subdivisions of states in the United States. This dataset contains population data for counties and states in the US from 2010 to 2015. [See this document](http://www.census.gov/popest/data/counties/totals/2015/files/CO-EST2015-alldata.pdf) for a description of the variable names.
#
# The census dataset (census.csv) should be loaded as census_df. Answer questions using this as appropriate.
#
# ### Question 5
# Which state has the most counties in it? (hint: consider the sumlevel key carefully! You'll need this for future questions too...)
#
# *This function should return a single string value.*

# In[5]:

census_df = pd.read_csv('census.csv')
census_df.head()


# In[2]:

def answer_five():
    df_filtered = census_df[census_df['SUMLEV'] == 50]
    state_df = pd.DataFrame()
    state_df['State'] = df_filtered['STNAME'].unique()
    state_df['County'] = 0
    state_df.set_index('State', inplace=True)
    for st in state_df.index:
        count = len(df_filtered[df_filtered['STNAME'] == st])
        state_df['County'].loc[st] = count
    return state_df['County'].argmax()
answer_five()


# ### Question 6
# Only looking at the three most populous counties for each state, what are the three most populous states (in order of highest population to lowest population)? Use `CENSUS2010POP`.
#
# *This function should return a list of string values.*

# In[22]:

def answer_six():
    df_filtered = census_df[census_df['SUMLEV'] == 50]
    state_df = pd.DataFrame()
    state_df['State'] = df_filtered['STNAME'].unique()
    state_df['Population'] = 0
    state_df.set_index('State', inplace=True)
    for st in state_df.index:
        count = sum(df_filtered[df_filtered['STNAME'] == st].nlargest(3, 'CENSUS2010POP')['CENSUS2010POP'])
        state_df['Population'].loc[st] = count
    return state_df.nlargest(3, 'Population').index.tolist()
answer_six()


# ### Question 7
# Which county has had the largest absolute change in population within the period 2010-2015? (Hint: population values are stored in columns POPESTIMATE2010 through POPESTIMATE2015, you need to consider all six columns.)
#
# e.g. If County Population in the 5 year period is 100, 120, 80, 105, 100, 130, then its largest change in the period would be |130-80| = 50.
#
# *This function should return a single string value.*

# In[167]:

def answer_seven():
    df_filtered = census_df[census_df['SUMLEV'] == 50]
    df_filtered = df_filtered.loc[:,['CTYNAME', 'POPESTIMATE2010', 'POPESTIMATE2011', 'POPESTIMATE2012', 'POPESTIMATE2013', 'POPESTIMATE2014', 'POPESTIMATE2015']]
    df_filtered = df_filtered.set_index('CTYNAME').reset_index()

    state_df = pd.DataFrame()
    state_df['State'] = df_filtered['CTYNAME']
    state_df['Count'] = 0
    state_df.set_index('State', inplace=True)
    for index, st in enumerate(state_df.index):
        count_max = df_filtered[df_filtered['CTYNAME'] == st].drop('CTYNAME', 1).apply(max, 1).loc[index]
        count_min = df_filtered[df_filtered['CTYNAME'] == st].drop('CTYNAME', 1).apply(min, 1).loc[index]
        state_df['Count'].loc[st] = count_max - count_min
    return state_df['Count'].argmax()
answer_seven()


# ### Question 8
# In this datafile, the United States is broken up into four regions using the "REGION" column.
#
# Create a query that finds the counties that belong to regions 1 or 2, whose name starts with 'Washington', and whose POPESTIMATE2015 was greater than their POPESTIMATE 2014.
#
# *This function should return a 5x2 DataFrame with the columns = ['STNAME', 'CTYNAME'] and the same index ID as the census_df (sorted ascending by index).*

# In[76]:

def answer_eight():
    df_filtered = census_df[census_df['SUMLEV'] == 50]
    df_index = df_filtered.reset_index()

    ans_df = pd.DataFrame()
    ans_df['STNAME'] = ''
    ans_df['CTYNAME'] = ''

    for index in df_index['index']:
        region = df_index[df_index['index'] == index]['REGION'].iloc[0]
        county_name = df_index[df_index['index'] == index]['CTYNAME'].iloc[0]
        pop2015 = df_index[df_index['index'] == index]['POPESTIMATE2015'].iloc[0]
        pop2014 = df_index[df_index['index'] == index]['POPESTIMATE2014'].iloc[0]
        pop_diff = pop2015-pop2014
        if((region == 1 or region == 2) and county_name.startswith('Washington') and pop_diff > 0):
            index = df_index[df_index['index'] == index]['index'].iloc[0]
            state_name = df_index[df_index['index'] == index]['STNAME'].iloc[0]
            data = pd.DataFrame({'STNAME' : [state_name], 'CTYNAME' : [county_name]}, index=[index])
            ans_df = ans_df.append(data)
    ans_df = ans_df[['STNAME', 'CTYNAME']]
    return ans_df

answer_eight()

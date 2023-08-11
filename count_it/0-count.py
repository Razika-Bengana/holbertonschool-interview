#!/usr/bin/python3
"""0-count"""

import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """recursive function that queries the Reddit API"""
    if counts is None:
        counts = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100}
    if after:
        params['after'] = after

    headers = {'User-Agent': 'studentapp/1.0 by ShortNegotiation8469'}
    response = requests.get(url, params=params, headers=headers)

    if response.status_code == 200:
        data = response.json()
        articles = data.get('data', {}).get('children', [])

        for article in articles:
            title = article['data']['title'].lower()
            for word in word_list:
                if word in title:
                    counts[word] = counts.get(word, 0) + title.count(word)

        after = data.get('data', {}).get('after')

        if after:
            count_words(subreddit, word_list, after, counts)
        else:
            sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
            for word, count in sorted_counts:
                print(f"{word}: {count}")

    else:
        print(f"Error: Unable to retrieve data from Reddit API\
(Status code: {response.status_code})")


subreddit = "programming"
word_list = ["python", "javascript", "java"]
count_words(subreddit, word_list)

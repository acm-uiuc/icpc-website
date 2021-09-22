# ACM-ICPC Website
This is the website repository for the ICPC team at UIUC.

## Quick Start
<pre><code>$ git clone https://github.com/acm-uiuc/icpc-website.git
$ cd icpc-website
$ jekyll serve --watch
$ open http://localhost:4000/</code></pre>

## Page Updates
Update meeting summaries in the _post file.
- File name format  "YYYY-MM-DD-Meeting-Title" 
- Include this segment at the top
---
layout: post
category: practices
time: 1:00 PM
description: Summary of Meeting 
---
	Category can be either practices or announcement depending on the post type.
	layout is always post
	time can be anytime (please just make it reasonable)
	description will be the small message under post on front page

## Adding Links
If you get a 404 after adding a link to the website, try this
<pre><code>$ git commit --allow-empty -m "Trigger rebuild"
$ git push </code></pre>

## Other Resources
Other resources can be found in [here](https://docs.google.com/presentation/d/1S6Cn7opfmwvdXv_hj0epf-f2VVPMVOSjQPr48xtk6Oc/edit#slide=id.g334dc67db_00).


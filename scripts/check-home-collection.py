from html.parser import HTMLParser
from pathlib import Path
import re

class HomeFeed(HTMLParser):
    def __init__(self):
        super().__init__()
        self.depth = 0
        self.links = []
    def handle_starttag(self, tag, attrs):
        attrs = dict(attrs)
        if tag == 'div':
            if attrs.get('id') == 'post-list': self.depth = 1
            elif self.depth: self.depth += 1
        if self.depth and tag == 'a' and '/posts/' in attrs.get('href', ''):
            self.links.append(attrs['href'])
    def handle_endtag(self, tag):
        if tag == 'div' and self.depth: self.depth -= 1

root = Path(__file__).resolve().parent.parent
feed = HomeFeed()
feed.feed((root / 'dist/index.html').read_text(encoding='utf8'))
acm_links = {x for x in feed.links if '/posts/acm-' in x}
assert acm_links == {'/posts/acm-index/'}, acm_links
assert (root / 'dist/posts/acm-keywords/index.html').exists()
assert len(list((root / 'dist/posts').glob('acm-*/index.html'))) >= 174
for article in (root / 'src/content/posts').glob('acm-*.md'):
    text = re.sub(r'(`{3,})cpp\n[\s\S]*?\n\1', '', article.read_text(encoding='utf8'))
    assert '## 整理记录' not in text, article.name
    assert '原代码' not in text, article.name
    assert '验证状态' not in text, article.name
print('Homepage has one ACM collection entry; inner pages remain reachable; editorial voice checks passed.')

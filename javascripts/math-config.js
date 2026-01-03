window.MathJax = {
  tex: {
    inlineMath: [['$', '$'], ['\\(', '\\)']],
    displayMath: [['$$', '$$'], ['\\[', '\\]']]
  },
  svg: {
    fontCache: 'global'
  },
  startup: {
    pageReady: function() {
      // 修改默认的页面就绪函数
      return MathJax.startup.defaultPageReady().then(function() {
        // 额外的初始化代码可以放在这里
        console.log('MathJax initialized');
      });
    }
  }
};
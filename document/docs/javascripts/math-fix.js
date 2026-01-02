// 修复 MathJax 在 instant navigation 下的渲染问题
(function() {
  'use strict';
  
  // 存储原始的 MathJax 配置
  const originalPageReady = window.MathJax && window.MathJax.startup && window.MathJax.startup.pageReady;
  
  // 自定义页面就绪函数
  function customPageReady() {
    return Promise.resolve().then(function() {
      // 执行原始的页面就绪函数
      if (originalPageReady) {
        return originalPageReady();
      }
      // 如果没有原始函数，使用默认的
      return window.MathJax.startup.defaultPageReady();
    }).then(function() {
      console.log('MathJax page ready');
    });
  }
  
  // 更新 MathJax 配置
  if (window.MathJax) {
    if (!window.MathJax.startup) {
      window.MathJax.startup = {};
    }
    window.MathJax.startup.pageReady = customPageReady;
  }
  
  // 监听页面变化
  document$.subscribe(function() {
    console.log('Page updated, re-rendering MathJax...');
    
    // 延迟执行以确保 DOM 完全更新
    setTimeout(function() {
      if (window.MathJax && window.MathJax.typesetPromise) {
        window.MathJax.typesetPromise().then(function() {
          console.log('MathJax re-rendered successfully');
        }).catch(function(err) {
          console.warn('MathJax re-render failed:', err);
        });
      }
    }, 200);
  });
  
})();
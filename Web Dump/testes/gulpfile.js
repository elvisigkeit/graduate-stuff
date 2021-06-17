var gulp = require('gulp');
var jasmine = require('gulp-jasmine');

var caminhoCodigoFonte = 'src/**/*.js';

gulp.task('testar', function(){gulp.src(caminhoCodigoFonte).pipe(jasmine())});

gulp.task('tdd-continuo', ['testar'], function() {
			gulp.watch(caminhoCodigoFonte, ['testar']);});

process.on('uncaughtException', function(e){console.error(e.stack);});

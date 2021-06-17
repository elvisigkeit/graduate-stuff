var Arvore = require('../prod/Arvore');

describe('Arvore', function() {
			it('deve possuir 5 frutos', function() {
					expect(new Arvore().obterFrutos().length).toBe(5);
			});
});

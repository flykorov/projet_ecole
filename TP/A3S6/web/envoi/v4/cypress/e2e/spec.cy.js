describe('Memory Game', () => {
  it('Visite', () => {
    cy.visit('http://localhost:8080')

  })

  it('Demarer partie legacy', () => {
    cy.visit('http://localhost:8080')
    cy.get('.bouton').click()
    cy.get('#size').type(10)
    cy.get('#timer').type(2)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()
  })

  it('Verifier vie legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(10)
    cy.get('#timer').type(2)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.get('#i3').should('be.visible')

    cy.tick(2000)

    cy.get('#item1').click()
    cy.get('#item2').click()

    cy.tick(1000)
    cy.get('#item0').click()
    cy.get('#item3').click()

    cy.tick(1000)



    cy.get('#i3').should('not.be.visible')

  })

  it('Verifier victoire legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle3 > .texte').should('not.be.visible')
    cy.get('.bouton').click()
    cy.get('#size').type(1)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('.rectangle3 > .texte').should('not.be.visible')

    cy.get('#item1').click()
    cy.get('#item0').click()

    cy.get('.rectangle3 > .texte').should('be.visible')

  })

  it('Verifier defaite legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#item1').click()
    cy.get('#item0').click()
    cy.tick(1000)

    cy.get('#item1').click()
    cy.get('#item0').click()
    cy.tick(1000)
    cy.get('.rectangle4 > .texte').should('not.be.visible')

    cy.get('#item1').click()
    cy.get('#item0').click()

    cy.get('.rectangle4 > .texte').should('be.visible')

  })

  it('Verifier defaite timer legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.tick(21000)
    

    cy.get('#item1').click()

    cy.get('.rectangle4 > .texte').should('be.visible')

  })

  it('Action carte legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)


    cy.get('#item0').click()
    cy.tick(1000)
    cy.get('#item0').click()



  })

  it('Compteur positif legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(1)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#item1').click()
    cy.get('#item0').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 1')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 0')

  })

  it('Compteur negatif legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#item1').click()
    cy.get('#item0').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 0')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 1')

  })

  it('Nombre de carte legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#item0').click()
    cy.get('#item19').click()

  })

  it('Verifier timer legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(10)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)
    cy.get('#timer2').invoke('text').should('eq', '9')
    cy.tick(5000)

    cy.get('#timer2').invoke('text').should('eq', '4')
    cy.tick(1000)
    cy.get('#timer2').invoke('text').should('eq', '3')
    cy.tick(3000)
    cy.get('#timer2').invoke('text').should('eq', '0')

    cy.tick(1000)
    cy.get('#timer3').invoke('text').should('eq', '9')
    cy.tick(5000)

    cy.get('#timer3').invoke('text').should('eq', '4')
    cy.tick(1000)
    cy.get('#timer3').invoke('text').should('eq', '3')
    cy.tick(3000)
    cy.get('#timer3').invoke('text').should('eq', '0')


  })

  it('Bouton restart legacy', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.bouton').click()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#item1').click()
    cy.get('#item0').click()

    cy.get('#btn2').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 0')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 0')

  })



  it('Demarer partie', () => {
    cy.visit('http://localhost:8080')
    cy.get('#size').type(10)
    cy.get('#timer').type(2)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()
  })

  it('Verifier vie', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('#size').type(10)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.get('#i3').should('be.visible')

    cy.tick(2000)

    cy.get('#card1').click()
    cy.get('#card2').click()

    cy.tick(1000)
    cy.get('#card0').click()
    cy.get('#card3').click()

    // cy.tick(2000)


    cy.get('#i3').should('not.be.visible')
    // cy.get('#i3').should('have.attr', 'src', '')

  })

  it('Verifier victoire', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle3 > .texte').should('not.be.visible')
    cy.get('#size').type(1)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('.rectangle3 > .texte').should('not.be.visible')

    cy.get('#card1').click()
    cy.get('#card0').click()

    cy.get('.rectangle3 > .texte').should('be.visible')

  })

  it('Verifier defaite', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(2000)

    cy.get('#card1').click()
    cy.get('#card0').click()
    cy.tick(2000)

    cy.get('#card1').click()
    cy.get('#card0').click()
    cy.tick(2000)
    cy.get('.rectangle4 > .texte').should('not.be.visible')

    cy.get('#card1').click()
    cy.get('#card0').click()

    cy.get('.rectangle4 > .texte').should('be.visible')

  })

  it('Verifier defaite timer', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.get('.rectangle4 > .texte').should('not.be.visible')
    cy.tick(21000)
    

    cy.get('#card1').click()

    cy.get('.rectangle4 > .texte').should('be.visible')

  })

  it('Action carte', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)


    cy.get('#card0').click()
    cy.tick(1000)
    cy.get('#card0').click()



  })

  it('Compteur positif', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.clock()
    cy.get('#size').type(1)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#card1').click()
    cy.get('#card0').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 1')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 0')

  })

  it('Compteur negatif', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.clock()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#card1').click()
    cy.get('#card0').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 0')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 1')

  })

  it('Nombre de carte', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(20)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#card0').click()
    cy.get('#card19').click()

  })

  it('Verifier timer', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('#size').type(20)
    cy.get('#timer').type(10)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)
    cy.get('#timer2').invoke('text').should('eq', '9')
    cy.tick(5000)

    cy.get('#timer2').invoke('text').should('eq', '4')
    cy.tick(1000)
    cy.get('#timer2').invoke('text').should('eq', '3')
    cy.tick(3000)
    cy.get('#timer2').invoke('text').should('eq', '0')

    cy.tick(1000)
    cy.get('#timer3').invoke('text').should('eq', '9')
    cy.tick(5000)

    cy.get('#timer3').invoke('text').should('eq', '4')
    cy.tick(1000)
    cy.get('#timer3').invoke('text').should('eq', '3')
    cy.tick(3000)
    cy.get('#timer3').invoke('text').should('eq', '0')


  })

  it('Bouton restart', () => {
    cy.visit('http://localhost:8080')
    cy.clock()
    cy.get('#size').type(20)
    cy.get('#timer').type(1)
    cy.get('#timer4').type(10)
    cy.get('#heart').type(3)
    cy.get('#submit').click()

    cy.tick(1000)

    cy.get('#card1').click()
    cy.get('#card0').click()

    cy.get('#btn2').click()

    cy.get('#bonne').invoke('text').should('eq', 'bonne reponse 0')
    cy.get('#mauvaise').invoke('text').should('eq', 'mauvaise reponse 0')

  })

})
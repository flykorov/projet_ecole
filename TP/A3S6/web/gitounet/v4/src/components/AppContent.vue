<template>
  <div class="rectangle">
    <div class="texte">Memory Game</div>
    <button :class="{bgGreenColor:legacyMode}" @click="changerHeritage" class="bouton">{{text}}</button>
    <GamePlay v-if="!legacyMode"/>
    <GameConfig v-if="legacyMode"/>
    <GamePlayLegacy v-if="legacyMode"/>
  </div>

  
</template>

<script>
import GameConfig from './GameConfig.vue'
import GamePlayLegacy from './GamePlayLegacy.vue'
import GamePlay from './GamePlay.vue'

export default {
  name: 'AppContent',
  components: {
    GameConfig,
    GamePlayLegacy,
    GamePlay,
  },

  data() {
    return {
      legacyMode: false,
      text: "activer mode heritage",
    }
  },

  methods: {
    changerHeritage() {
      this.legacyMode = !this.legacyMode
      this.text = this.legacyMode ? "desactiver mode heritage" : "activer mode heritage"
    },
  },

}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.rectangle {
  margin-top: 60px;
}

.bgGreenColor {
  background-color: green;
  color: white;
}

.bouton {
  width: 200px;
  height: 50px;
}
</style>
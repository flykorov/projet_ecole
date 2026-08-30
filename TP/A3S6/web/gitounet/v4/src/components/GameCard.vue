<template>
	<li class="flex-item">
		<img class="image" width="200" v-bind:id="`card${cardId}`" v-bind:src="`image/${imageId}.jpeg`" v-on:click="cliker"/>
	</li>
</template>

<script>
export default {
	name: 'GameCard',
	props: {
		cardId: { type: String, default: "0"},
		imageId: { type: String, default: "10"},
	},
	methods: {
		cliker() {
			this.$emit('image-cliked', this.cardId)
		},
	}
}

</script>